#ifndef DLOPEN_TEST_REGISTRY_HPP
#define DLOPEN_TEST_REGISTRY_HPP

#include "plugin.hpp"

#include <memory>

namespace dlopen_test {

void setPlugin(std::unique_ptr<Plugin>&& value);

Plugin& getPlugin();

}

#endif
