#ifndef concrete_aggregate_h
#define concrete_aggregate_h

#include <iostream>
#include <memory>
#include <type_traits>

#include "aggregate.h"
#include "concrete_iterator.h"

template<typename T>
using IsIntegral = std::enable_if_t<std::is_integral<T>::value>;

template<typename T>
class ConcreteIterator;

template<typename T>
class ConcreteAggregate : public Aggregate<T>, public std::enable_shared_from_this<ConcreteAggregate<T>>
{
private:
    T size_;
    std::shared_ptr<T> list_;

public:
    ConcreteAggregate() = delete;

    template<typename T_ = T, typename = IsIntegral<T_>>
    explicit ConcreteAggregate(T_&& size) : size_(std::forward<T_>(size)),
                                        //    list_(std::make_shared<T_>(size_))
                                           list_(new T[size_])
    {

    }

    ~ConcreteAggregate() = default;
    
    virtual int size() override;

    virtual int at(int index) override;

    virtual std::shared_ptr<Iterator<T>> create_iterator() override;
};

template<typename T>
int ConcreteAggregate<T>::size() 
{
    return size_;
}

template<typename T>
int ConcreteAggregate<T>::at(int index) 
{
    auto test = list_.get();
    std::cout << index << " " << list_.get()[index] << std::endl;
    return list_.get()[index];
}

template<typename T>
std::shared_ptr<Iterator<T>> ConcreteAggregate<T>::create_iterator()
{
    return std::make_shared<ConcreteIterator<T>>(this->shared_from_this()); 
}

#endif 