#ifndef INCLUDE_FURNITURE_FACTORY_H
#define INCLUDE_FURNITURE_FACTORY_H

#include "material.h"
#include "furniture_abstract.h"
#include "plastic_factory.h"
#include "wood_factory.h"

#include <iostream>
#include <memory>

template<typename T>
class FunitureFactory
{
private:
    FunitureFactory() = default;

public:
    ~FunitureFactory () = default;

    static decltype(auto) getFactory(Material material);
};

template<typename T>
decltype(auto) FunitureFactory<T>::getFactory(Material material)
{
    switch(material) {
        case Material::PLASTIC:
            std::cout << "Test plastic factory" << std::endl;

            // template<typename U>
            return std::make_unique<PlasticFactory<T>>();
        case Material::WOOD:
            std::cout << "Test wood factory" << std::endl;

            // template<typename U>
            return std::make_unique<PlasticFactory<T>>();
        default:
            throw std::invalid_argument("Received wrong argument");
    }
}


#endif