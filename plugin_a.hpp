#ifndef DLOPEN_TEST_PLUGIN_A_HPP
#define DLOPEN_TEST_PLUGIN_A_HPP

#include "plugin.hpp"

namespace dlopen_test {

struct PluginA : Plugin {
    std::unique_ptr<Object> make_object() override;
};

}

#endif
