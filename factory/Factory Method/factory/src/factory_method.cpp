#include "../include/factory_method.h"
     
// template<typename T, std::size_t MAX_SIZE>
// Factory<T, MAX_SIZE>::Factory()
// {

// }

// template<typename T, std::size_t MAX_SIZE>
// std::shared_ptr<PizzaStore<T, MAX_SIZE>> Factory<T, MAX_SIZE>::choose_location(eLocationType locationType)
// {
//     std::shared_ptr<PizzaStore<T, MAX_SIZE>> storeLocation;
//     switch (locationType) 
//     {
//         case NEWYORK:
//         {
//             storeLocation = std::make_shared<PizzaStore<T, MAX_SIZE>>();
//         }
//     }

//     return storeLocation;
// }