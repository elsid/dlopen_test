#ifndef DLOPEN_TEST_INITIALIZER_HPP
#define DLOPEN_TEST_INITIALIZER_HPP

#include "registry.hpp"

#include <memory>

namespace dlopen_test {
    template <class T>
    struct Initializer {
        explicit Initializer() {
            setPlugin(std::make_unique<T>());
        }
    };
}

#endif
