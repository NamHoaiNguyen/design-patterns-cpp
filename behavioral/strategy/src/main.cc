#include "../include/sort_algorithm.h"
#include "../include/sorted_list.h"
#include "../include/merge_sort.h"
#include "../include/quick_sort.h"
#include "../include/selection_sort.h"

#include <iostream>
#include <list>
#include <memory>
#include <string>

int main()
{
    /*Test strategy pattern and template specialization*/
    /*auto = std::unique_ptr<SortedList<std::string>>*/
    auto test_merge_sort_template_specialization = std::make_unique<SortedList<std::string>>();
    test_merge_sort_template_specialization->add("C Core");
    test_merge_sort_template_specialization->add("C Design Pattern");
    test_merge_sort_template_specialization->add("C Library");
    test_merge_sort_template_specialization->add("C Framework");
    test_merge_sort_template_specialization->print_list();
    test_merge_sort_template_specialization->set_sort_algorithm(std::make_unique<MergeSort<std::string>>());
    test_merge_sort_template_specialization->sort();

    /*Test strategy pattern and primary tempalet*/
    auto test_quick_sort_primary_template = std::make_unique<SortedList<int>>();
    test_quick_sort_primary_template->add(4);
    test_quick_sort_primary_template->add(2);
    test_quick_sort_primary_template->add(1);
    test_quick_sort_primary_template->add(3);
    test_quick_sort_primary_template->print_list();
    test_quick_sort_primary_template->set_sort_algorithm(std::make_unique<QuickSort<int>>());
    test_quick_sort_primary_template->sort();

    return 0;
}