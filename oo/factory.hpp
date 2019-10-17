#pragma once

#include "kinds.hpp"

#include <memory>
#include <stdexcept>

namespace oo {

class animal {
public:
    virtual ~animal() {}

    virtual void pet() = 0;
};


class cat : public animal {
public:
    void pet() override {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};


class dog : public animal {
public:
    void pet() override {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};


class hamster : public animal {
public:
    void pet() override {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};


class elephant : public animal {
public:
    void pet() override {
        ++m_pet_count;
    }

    inline static unsigned int m_pet_count = 0;
};

using handle = std::unique_ptr<animal>;

handle create_animal(Kind const kind) {
    switch (kind)
    {
    case Kind::Cat:
        return std::make_unique<cat>();
        break;
    case Kind::Dog:
        return std::make_unique<dog>();
        break;
    case Kind::Hamster:
        return std::make_unique<hamster>();
        break;
    case Kind::Elephant:
        return std::make_unique<elephant>();
        break;
    }
    throw std::logic_error("Unknown animal kind");
}

}
