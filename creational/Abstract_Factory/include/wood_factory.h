#ifndef INCLUDE_WOOD_FACTORY_H
#define INCLUDE_WOOD_FACTORY_H

#include "furniture_abstract.h"
#include "wood_chair.h"
#include "wood_table.h"

#include <memory>

template<typename T>
class WoodFactory : public FurnitureAbstract<T>
{
private:

public:
    ~WoodFactory() = default;

    std::unique_ptr<Chair<T>> create_chair() override;

    std::unique_ptr<Table<T>> create_table() override;
};

template<typename T>
std::unique_ptr<Chair<T>> WoodFactory<T>::create_chair()
{
    return std::make_unique<WoodChair<T>>();
}

template<typename T>
std::unique_ptr<Table<T>> WoodFactory<T>::create_table()
{
    return std::make_unique<WoodTable<T>>();
}

#endif