#ifndef concrete_iterator
#define concrete_iterator

#include "concrete_aggregate.h"

#include <type_traits>

template<typename T>
using IsPointer = 
std::enable_if_t<std::is_pointer_v<T>>;


template<typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::shared_ptr<ConcreteAggregate<T>> conAggr_l;
    unsigned int index;

public:
    template<typename = IsPointer<T>>
    explicit ConcreteIterator(std::shared_ptr<ConcreteAggregate<T>> conAggr) : conAggr_l(conAggr), index(0)
    {

    }

    ~ConcreteIterator() = default;

    virtual void first() override;

    virtual void next() override;

    virtual bool isDone() const override;

    virtual void currentItem() const override;
};

template<typename T>
void ConcreteIterator<T>::first()
{
    index = 0;
    // return index;
}

template<typename T>
void ConcreteIterator<T>::next()
{
    index++;
}

template<typename T>
void ConcreteIterator<T>::currentItem() const
{
    if (isDone())   return;

    return conAggr_l->at(index);
}

template<typename T>
bool ConcreteIterator<T>::isDone() const 
{
    return index >= conAggr_l->size();
}

#endif