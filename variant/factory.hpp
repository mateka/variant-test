#pragma once

#include "kinds.hpp"

#include <variant>
#include <stdexcept>

namespace variant {

class cat {
public:
    void pet() {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};


class dog {
public:
    void pet() {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};


class hamster {
public:
    void pet() {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};


class elephant {
public:
    void pet() {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};


using handle = std::variant<cat, dog, hamster, elephant>;

handle create_animal(Kind const kind) {
    switch (kind)
    {
    case Kind::Cat:
        return cat{};
        break;
    case Kind::Dog:
        return dog{};
        break;
    case Kind::Hamster:
        return hamster{};
        break;
    case Kind::Elephant:
        return elephant{};
        break;
    }
    throw std::logic_error("Unknown animal kind");
}

}
