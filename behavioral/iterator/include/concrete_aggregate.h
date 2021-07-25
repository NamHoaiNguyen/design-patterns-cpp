#ifndef concrete_aggregate
#define concrete_aggregate

#include <iostream>
#include <memory>
#include <type_traits>

#include "aggregate.h"

template<typename T>
using IsIntegral = std::enable_if_t<std::is_integral<T>::type>;

template<typename T>
class ConcreteAggregate : public Aggregate<T> 
{
private:
    T size_;
    // template<typename T_ = T, typename = IsIntegral>
    // std::list<T_> list;
    std::shared_ptr<T> list_;

public:
    ConcreteAggregate() = delete;

    template<typename T_ = T, typename = IsIntegral<T>>
    explicit ConcreteAggregate(T&& size) : size_(std::forward<T>(size)), list_(new T[size_]) 
    {

    }

    ~ConcreteAggregate() 
    {

    }
    
    virtual int size() const override;

    virtual int at(unsigned int index) const override;

    virtual std::shared_ptr<Iterator<T>> create_iterator() override;
};

template<typename T>
int ConcreteAggregate<T>::size() const 
{
    size_ = 0;
}

template<typename T>
int ConcreteAggregate<T>::at(unsigned int index) const 
{
    return list_[index];
}

template<typename T>
std::shared_ptr<Iterator<T>> ConcreteAggregate<T>::create_iterator()
{
    // return std::shared_ptr<A>
}

#endif 