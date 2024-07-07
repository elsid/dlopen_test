#ifndef DLOPEN_TEST_PLUGIN_HPP
#define DLOPEN_TEST_PLUGIN_HPP

#include "object.hpp"

#include <memory>

namespace dlopen_test {

struct Plugin {
    virtual ~Plugin();

    virtual std::unique_ptr<Object> make_object() = 0;
};

}

#endif
