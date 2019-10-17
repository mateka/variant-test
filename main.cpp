#include "oo/factory.hpp"
#include "variant/factory.hpp"
#include "kinds.hpp"

#include <iomanip>
#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>


template<typename Factory>
auto create_n(Factory f, std::size_t const n) -> std::vector<decltype(f(std::declval<Kind>()))> {
    std::random_device r;
    std::default_random_engine generator(r());
    std::uniform_int_distribution<int> distribution{0, 3};

    std::vector<decltype(f(std::declval<Kind>()))> result;
    std::generate_n(
        std::back_inserter(result), n,
        [&generator, &distribution, &f]() {
            return f(static_cast<Kind>(distribution(generator)));
        }
    );
    return result;
}


template<typename Handle, typename TestFunction>
auto measure(std::vector<Handle>& v, TestFunction fn) {
    auto start = std::chrono::high_resolution_clock::now();
    for(auto& e : v)
        fn(e);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}

auto test_oo(std::size_t const n) {
    auto v = create_n(oo::create_animal, n);
    return measure(v, [](auto& e) { e->pet(); });
}

auto test_variant(std::size_t const n) {
    auto v = create_n(variant::create_animal, n);
    return measure(v, [](auto& e) {
        std::visit([](auto& arg) { arg.pet(); }, e);
    });
}

template<typename TestFun>
auto repeat(TestFun fn, std::size_t const n, std::size_t const repetitions) {
    auto fn_time = fn(n);
    for(std::size_t i = 1; i < repetitions; ++i)
        fn_time += fn(n);
    return fn_time;
}

void test_n(std::size_t const n, std::size_t const repetitions) {
    using seconds = std::chrono::duration<float>;
    auto oo      = repeat(test_oo,       n, repetitions);
    auto variant = repeat(test_variant,  n, repetitions);

    auto const oo_time      = std::chrono::duration_cast<seconds>(oo).count();
    auto const variant_time = std::chrono::duration_cast<seconds>(variant).count();
    std::cout
        << std::setw(12) << n
        << std::setw(12) << repetitions
        << std::setw(12) << n * repetitions
        << std::setw(12) << oo_time
        << std::setw(12) << variant_time
        << std::setw(12) << (variant_time / oo_time)
        << std::endl;
}


int main() {
    std::cout << "Testing classic OO vs variant OO" << std::endl;
    std::cout
        << std::setw(12) << "Objects"
        << std::setw(12) << "Repetitions"
        << std::setw(12) << "Calls"
        << std::setw(12) << "OO"
        << std::setw(12) << "Variant"
        << std::setw(12) << "Ratio [variant / oo]" << std::endl;

    test_n(       10, 10000000);
    test_n(      100, 1000000);
    test_n(     1000, 100000);
    test_n(  1000000, 100);
    test_n(100000000, 1);
    test_n(150000000, 1);
    test_n(200000000, 1);
    test_n(250000000, 1);
}
