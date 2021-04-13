#include "pizza.h"
#include <memory>

int main()
{
    PizzaStore<std::string, 10> *location_store = new PizzaStore<std::string, 10>();
    // std::unique_ptr<PizzaStore<std::string, 10>> location_store = std::make_unique<PizzaStore<std::string, 10>();
}