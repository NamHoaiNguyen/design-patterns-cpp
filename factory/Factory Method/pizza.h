#ifndef FAC_FACMETHOD_PIZZA
#define FAC_FACMETHOD_PIZZA

#include <array>
#include <iostream>
#include <vector>

template<typename T, std::size_t NUMERICAL_ORDER>
class PizzaStore {
protected:
    std::array<T, NUMERICAL_ORDER> number_stores;

public:
    virtual ~PizzaStore() = 0;
    virtual void pizza_order() = 0;
    virtual T store_describe() = 0;
    virtual size_t get_number_stores() = 0;
};

#endif