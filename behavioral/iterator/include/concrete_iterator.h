#ifndef concrete_iterator_h
#define concrete_iterator_h

#include "iterator.h"
#include "concrete_aggregate.h"

#include <type_traits>

template<typename T>
using IsPointer = 
std::enable_if_t<std::is_pointer<T>::value>;

template<typename T>
class ConcreteAggregate;

template<typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::shared_ptr<ConcreteAggregate<T>> conAggr_l;
    int index;

public:
    ConcreteIterator() 
    {

    }
    // template<typename = IsPointer<T>>
    explicit ConcreteIterator(std::shared_ptr<ConcreteAggregate<T>> conAggr) : conAggr_l(conAggr)
    {

    }

    ~ConcreteIterator() = default;

    virtual void first() override;

    virtual void next() override;

    virtual bool isDone() const override;

    virtual T currentItem() const override;
};

template<typename T>
void ConcreteIterator<T>::first()
{
    index = 0;
}

template<typename T>
void ConcreteIterator<T>::next()
{
    index++;
}

template<typename T>
T ConcreteIterator<T>::currentItem() const
{
    if (isDone())   return -1;

    return conAggr_l->at(index);
}

template<typename T>
bool ConcreteIterator<T>::isDone() const 
{
    return index >= conAggr_l->size();
}

#endif