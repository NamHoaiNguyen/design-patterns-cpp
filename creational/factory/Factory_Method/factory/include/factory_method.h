#ifndef FAC_METHOD_FACTORY_INCLUDE_FACTORYMETHOD
#define FAC_METHOD_FACTORY_INCLUDE_FACTORYMETHOD

#include "../../pizza_store/pizza.h"
#include "../../pizza_store/newyork/ny_store.h"
#include "../../pizza_store/oakland/oakland_store.h"

template<typename T, std::size_t MAX_SIZE>
class Factory {
public:
    Factory();
    static std::shared_ptr<PizzaStore<T, MAX_SIZE>> choose_location(eLocationType locationType);
};


template<typename T, std::size_t MAX_SIZE>
Factory<T, MAX_SIZE>::Factory()
{

}

/*Cant use unique_ptr cause of having situation that have more than one call to this function*/
template<typename T, std::size_t MAX_SIZE>
std::shared_ptr<PizzaStore<T, MAX_SIZE>> Factory<T, MAX_SIZE>::choose_location(eLocationType locationType)
{
    std::shared_ptr<PizzaStore<T, MAX_SIZE>> storeLocation;
    switch (locationType) 
    {
        case NEWYORK:
        {
            storeLocation = std::make_shared<NewYork<T, MAX_SIZE>>();
        }
        case OAKLAND:
        {
            storeLocation = std::make_shared<Oakland<T, MAX_SIZE>>();
        }
    }

    return storeLocation;
}

#endif