#ifndef FAC_FACMETHOD_PIZZA
#define FAC_FACMETHOD_PIZZA

#include <array>
#include <cassert>
#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>

enum eLocationType{
    NEWYORK = 0,
    OAKLAND,
};

template<typename T, std::size_t MAX_SIZE>
class PizzaStore {
// protected:
//     std::array<T, MAX_SIZE> number_stores;
public:
    virtual void pizza_order() = 0;
    virtual std::string store_describe(std::string const&) = 0;
    virtual void add_new_store(T const&) = 0;
    virtual void delete_store() = 0;
    virtual std::size_t get_number_stores() = 0;
};

#endif