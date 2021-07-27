#ifndef aggregate_h
#define aggregate_h

#include "iterator.h"

#include <iostream>
#include <memory>

template <typename T>
class Aggregate {
public:
    ~Aggregate() { }
        
    virtual int size()  = 0;

    virtual int at(int index) = 0;

    virtual std::shared_ptr<Iterator<T>> create_iterator() = 0;
};

#endif 