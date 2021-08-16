#ifndef INCLUDE_PROTOTYPE_H
#define INCLUDE_PROTOTYPE_H

#include <memory>

template<typename T>
class Prototype {
public:
    Prototype() = default;

    virtual std::shared_ptr<Prototype<T>> clone() = 0;

    virtual void print_string() = 0;
};

#endif