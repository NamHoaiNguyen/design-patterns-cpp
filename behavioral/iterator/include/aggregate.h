#ifndef aggregate
#define aggregate

#include <iostream>

template <typename T>
class Aggregate {
public:
    Aggregate() = default;
    virtual void create_iterator() = 0;
};

#endif 