#ifndef INCLUDE_QUICK_SORT_H
#define INCLUDE_QUICK_SORT_H

#include "sort_algorithm.h"

#include <iostream>
#include <list>
#include <string>

template<typename T>
class QuickSort : public SortAlgorithm<T> {
public:
    QuickSort() = default;

    void sort() override;
};

template<typename T>
void QuickSort<T>::sort() {
    std::cout << "Quick sort in primary template" << std::endl;
}

template<>
class QuickSort<std::string> : public SortAlgorithm<std::string> {
public:
    QuickSort() = default;

    void sort() override;
};

void QuickSort<std::string>::sort() {
    std::cout << "Quick sort in template specialization" << std::endl;
}

#endif