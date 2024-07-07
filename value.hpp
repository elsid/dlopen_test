#ifndef DLOPEN_TEST_VALUE_HPP
#define DLOPEN_TEST_VALUE_HPP

#include "object.hpp"

#include <iostream>

namespace dlopen_test {

template <class T>
struct Value final : Object {
    T value;

    explicit Value(const T& value) : value(value) {}

    void f() override {
        std::cout << "Value::" << __func__ << " " << value << std::endl;
    }
};

}

#endif
