#ifndef INCLUDE_SELECTION_SORT_H
#define INCLUDE_SELECTION_SORT_H

#include "sort_algorithm.h"

#include <iostream>
#include <list>
#include <string>

template<typename T>
class SelectionSort : public SortAlgorithm<T> {
public:
    SelectionSort() = default;

    void sort() override;
};

template<typename T>
void SelectionSort<T>::sort() {
    std::cout << "Selection sort in primary template" << std::endl;
}

template<>
class SelectionSort<std::string> : public SortAlgorithm<std::string> {
public:
    SelectionSort() = default;

    void sort() override;
};

void SelectionSort<std::string>::sort() {
    std::cout << "Selection sort in template specialization" << std::endl;
}

#endif