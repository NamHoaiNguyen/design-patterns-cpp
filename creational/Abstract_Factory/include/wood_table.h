#ifndef INCLUDE_WOOD_TABLE_H
#define INCLUDE_WOOD_TABLE_H

#include <iostream>

template<typename T>
class WoodTable : public Table<T>
{
public:
    void create() override;
};

template<typename T>
void WoodTable<T>::create()
{
    std::cout << "Create wood table" << std::endl;
}

#endif