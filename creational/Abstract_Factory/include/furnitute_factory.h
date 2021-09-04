#ifndef INCLUDE_FURNITURE_FACTORY_H
#define INCLUDE_FURNITURE_FACTORY_H

#include "material.h"
#include "furniture_abstract.h"
#include "plastic_factory.h"
#include "wood_factory.h"

#include <iostream>
#include <memory>

template<typename T>
class FurnitureFactory
{
private:
    FurnitureFactory() = default;

public:
    ~FurnitureFactory () = default;

    static std::unique_ptr<FurnitureAbstract<T>> getFactory(Material material);
};


/*NOTE: CAN'T USE DECLTYPE(AUTO) IF FUNCTION HAVE DIFFENT RETURN VALUES(EXAMPLE:EACH CASE IN SWITCH COMMAND RETURN OTHER TYPES)*/
/*HOW TO FIX: RETURN TYPE IS POINTER INTERFACE(POLYRMORPHISM)*/
template<typename T>
std::unique_ptr<FurnitureAbstract<T>> FurnitureFactory<T>::getFactory(Material material)
{
    switch(material) 
    {
        case Material::PLASTIC:
            std::cout << "Test plastic factory" << std::endl;
            return std::make_unique<PlasticFactory<T>>();
        case Material::WOOD:
            std::cout << "Test wood factory" << std::endl;
            return std::make_unique<WoodFactory<T>>();
        default:
            throw std::invalid_argument("Received wrong argument");
    }
}

#endif