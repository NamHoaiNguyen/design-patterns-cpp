#ifndef FAC_FACMETHOD_PIZZASTORE_NY
#define FAC_FACMETHOD_PIZZASTORE_NY

#include "../pizza.h"

template<typename T, std::size_t NUMERICAL_ORDER>
class NewYork : public PizzaStore<T> {
public:
    virtual ~PizzaStore() override;
    virtual void pizza_order() override;
    virtual T store_describe() override;
    virtual size_t get_number_store() override;
};

template<typename T, std::size_t NUMERICAL_ORDER>
void NewYork<T, NUMERICAL_ORDER>::pizza_order()
{
    return;   
}

template<typename T, std::size_t NUMERICAL_ORDER>
T NewYork<T, NUMERICAL_ORDER>::store_describe()
{
    
}

template<typename T, std::size_t NUMERICAL_ORDER>
std::size_t NewYork<T, NUMERICAL_ORDER>::get_number_store()
{
    return number_stores.size();
}
#endif;