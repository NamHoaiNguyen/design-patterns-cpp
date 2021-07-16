#ifndef concrete_aggregate
#define concrete_aggregate

#include <iostream>

#include "aggregate.h"

template<typename T>
class ConcreteAggregate : public Aggregate<T> 
{
public:
    ConcreteAggregate() = default;
    virtual void create_iterator() override;
};

template<typename T>
void ConcreteAggregate<T>::create_iterator()
{

}

#endif 