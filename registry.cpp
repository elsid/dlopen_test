#include "registry.hpp"

#include <stdexcept>
#include <string>

#include <dlfcn.h>

namespace dlopen_test {

namespace {

struct Dlclose {
    void operator()(void* value) { dlclose(value); }
};

std::unique_ptr<void, Dlclose> library;
std::unique_ptr<Plugin> plugin;

}

void setPlugin(std::unique_ptr<Plugin>&& value) {
    plugin = std::move(value);
}

Plugin& getPlugin() {
    if (plugin != nullptr) {
        return *plugin;
    }
    void* const handle = dlopen("libplugin_a.so", RTLD_LAZY | RTLD_GLOBAL);
    if (handle == nullptr) {
        throw std::runtime_error("Failed to load library: " + std::string(dlerror()));
    }
    library.reset(handle);
    if (plugin == nullptr) {
        throw std::runtime_error("Plugin is not loaded");
    }
    return *plugin;
}

}
