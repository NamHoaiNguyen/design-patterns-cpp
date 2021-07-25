#ifndef aggregate
#define aggregate

#include "iterator.h"

#include <iostream>
#include <memory>

template <typename T>
class Aggregate {
public:
    Aggregate() = default;
        
    virtual int size() const = 0;

    virtual int at(unsigned int index) const = 0;

    virtual std::shared_ptr<Iterator<T>> create_iterator() = 0;
};

#endif 