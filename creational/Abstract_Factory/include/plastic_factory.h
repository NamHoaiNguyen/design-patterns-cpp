#ifndef INCLUDE_PLASTIC_FACTORY_H
#define INCLUDE_PLASTIC_FACTORY_H

#include "furniture_abstract.h"
#include "plastic_chair.h"
#include "plastic_table.h"

#include <memory>

template<typename T>
class PlasticFactory : public FurnitureAbstract<T> 
{
public:
    PlasticFactory() = default;

    std::unique_ptr<Chair<T>> create_chair() override;

    std::unique_ptr<Table<T>> create_table() override;
};

template<typename T>
std::unique_ptr<Chair<T>> PlasticFactory<T>::create_chair()
{
    return std::make_unique<PlasticChair<T>>();
}

template<typename T>
std::unique_ptr<Table<T>> PlasticFactory<T>::create_table()
{
    return std::make_unique<PlasticTable<T>>();
}

#endif