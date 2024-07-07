#include "plugin_a.hpp"

#include "initializer.hpp"
#include "value.hpp"

namespace dlopen_test {

static Initializer<PluginA>* initializer = new Initializer<PluginA>();

std::unique_ptr<Object> PluginA::make_object() {
    auto result = std::make_unique<Value<int>>(42);
    Value<int>& ref = *result;
    std::cout << "PluginA::" << __func__ << " type of original object: " << typeid(ref).name() << " " << typeid(ref).hash_code() << std::endl;
    return result;
}

}
