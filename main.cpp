#include "registry.hpp"
#include "value.hpp"

#include <iostream>

int main() {
    dlopen_test::Plugin& a = dlopen_test::getPlugin();
    std::unique_ptr<dlopen_test::Object> o = a.make_object();
    o->f();
    dlopen_test::Object& ref = *o;
    std::cout << __func__ << " type by declaration: " << typeid(dlopen_test::Value<int>).name() << " " << typeid(dlopen_test::Value<int>).hash_code() << std::endl;
    std::cout << __func__ << " type by base reference: " << typeid(ref).name() << " " << typeid(ref).hash_code() << std::endl;
    dlopen_test::Value<int>& v = dynamic_cast<dlopen_test::Value<int>&>(ref);
    std::cout << __func__ << " type by casted reference: " << typeid(v).name() << " " << typeid(v).hash_code() << std::endl;
    std::cout << __func__ << " value: " << v.value << std::endl;
    return 0;
}
