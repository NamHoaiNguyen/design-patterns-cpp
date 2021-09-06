#ifndef INCLUDE_SORTED_LIST_H
#define INCLUDE_SORTED_LIST_H

#include "sort_algorithm.h"

#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>

/*Primary template*/
template<typename T>
class SortedList {
private:
    std::unique_ptr<SortAlgorithm<T>> sortAlgorithm_;
    std::list<T> items_;

public: 
    SortedList() {
        std::cout << "Constructor of primary template" << std::endl;
    }

    void set_sort_algorithm(std::unique_ptr<SortAlgorithm<T>>&& sortAlgorithm);

    void add(T name);

    void sort();

    void print_list();
};

template<typename T>
void SortedList<T>::set_sort_algorithm(std::unique_ptr<SortAlgorithm<T>>&& sortAlgorithm) {
    this->sortAlgorithm_ = std::move(sortAlgorithm); 
}

template<typename T>
void SortedList<T>::add(T name) {
    items_.push_front(name);
}

template<typename T>
void SortedList<T>::sort() {
    sortAlgorithm_->sort();
}

template<typename T>
void SortedList<T>::print_list() {
    for (const auto& elem : items_) {
        std::cout << elem << " -> ";
    }
    std::cout << std::endl;    
}

/*Template specialization*/
template<>
class SortedList<std::string> {
private:
    std::unique_ptr<SortAlgorithm<std::string>> sortAlgorithm_;
    std::list<std::string> items_;

public: 
    SortedList() {
        std::cout << "Constructor of template specialization" << std::endl;
    }

    void set_sort_algorithm( std::unique_ptr<SortAlgorithm<std::string>>&& sortAlgorithm);

    void add(std::string name);

    void sort();
    
    void print_list();
};

void SortedList<std::string>::set_sort_algorithm(std::unique_ptr<SortAlgorithm<std::string>>&& sortAlgorithm) {
    this->sortAlgorithm_ = std::move(sortAlgorithm);
}

void SortedList<std::string>::add(std::string name) {
    items_.push_front(name);
}

void SortedList<std::string>::sort() {
    sortAlgorithm_->sort();
}

void SortedList<std::string>::print_list() {
    for (const auto& elem : items_) {
        std::cout << elem << " -> ";
    }
    std::cout << std::endl;
}

#endif