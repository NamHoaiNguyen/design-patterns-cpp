#ifndef INCLUDE_MERGE_SORT_H
#define INCLUDE_MERGE_SORT_H

#include "sort_algorithm.h"

#include <iostream>
#include <list>
#include <string>

template<typename T>
class MergeSort : public SortAlgorithm<T> {
public:
    MergeSort() = default;

    void sort() override;
};

template<typename T>
void MergeSort<T>::sort() {
    std::cout << "Merge sort in primary template" << std::endl;
}

template<>
class MergeSort<std::string> : public SortAlgorithm<std::string> {
public:
    MergeSort() = default;

    void sort() override;
};

void MergeSort<std::string>::sort() {
    std::cout << "Merge sort in template specialization" << std::endl;
}


#endif