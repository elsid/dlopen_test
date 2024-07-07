#ifndef DLOPEN_TEST_OBJECT_HPP
#define DLOPEN_TEST_OBJECT_HPP

namespace dlopen_test {

struct Object {
    virtual ~Object();

    virtual void f() = 0;
};

}

#endif
