#include "pizza_store/pizza.h"
#include "pizza_store/newyork/ny_store.h"
#include "pizza_store/oakland/oakland_store.h"


int main()
{
    std::unique_ptr<PizzaStore<std::string, 20>> newyork_location
    = std::make_unique<NewYork<std::string, 20>>(); 
    std::unique_ptr<PizzaStore<std::string, 10>> oakland_location
    = std::make_unique<Oakland<std::string, 10>>(); 


    std::string location_ny{"NewYork"};
    std::cout << newyork_location->store_describe(location_ny) << " " << newyork_location->get_number_stores() << std::endl;
    std::string location_oak{"Oakland"};
    std::cout << oakland_location->store_describe(location_oak) << " " << oakland_location->get_number_stores() << std::endl;

    return 0;
}
