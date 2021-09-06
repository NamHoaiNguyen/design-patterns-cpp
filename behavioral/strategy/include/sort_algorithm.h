#ifndef INCLUDE_SORT_ALGORITHM_H
#define INCLUDE_SORT_ALGORITHM_H

#include <list>

template<typename T>
class SortAlgorithm {
private:

public:
    SortAlgorithm() = default;

    virtual void sort() = 0;
};

#endif