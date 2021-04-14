#ifndef FAC_FACMETHOD_PIZZASTORE_NY
#define FAC_FACMETHOD_PIZZASTORE_NY

#include "../pizza.h"

template<typename T, std::size_t MAX_SIZE>
class NewYork : public PizzaStore<T, MAX_SIZE> {
private:
    std::array<T, MAX_SIZE> number_stores;
    std::size_t numStores;   /*current number of stores*/

public:
    NewYork();
    virtual void pizza_order() override;
    virtual std::string store_describe(std::string const&) override;
    // virtual size_t get_number_stores() override;
    virtual void add_new_store(const T& elem) override; 
    virtual void delete_store() override;
    virtual std::size_t get_number_stores() override;
};

template<typename T, std::size_t MAX_SIZE>
NewYork<T, MAX_SIZE>::NewYork() : numStores{0}
{

}

template<typename T, std::size_t MAX_SIZE>
void NewYork<T, MAX_SIZE>::pizza_order()
{
    return;   
}

template<typename T, std::size_t MAX_SIZE>
std::string NewYork<T, MAX_SIZE>::store_describe(std::string const& value)
{
    return value;
}

template<typename T, std::size_t MAX_SIZE>
void NewYork<T, MAX_SIZE>::add_new_store(const T& value)
{    
    assert(numStores < MAX_SIZE);
    number_stores[numStores] = value;
    ++numStores;
}

template<typename T, std::size_t MAX_SIZE>
void NewYork<T, MAX_SIZE>::delete_store()
{
    assert(!number_stores.empty());
    --numStores;
}

template<typename T, std::size_t MAX_SIZE>
std::size_t NewYork<T, MAX_SIZE>::get_number_stores()
{
    return number_stores.size();
}

#endif