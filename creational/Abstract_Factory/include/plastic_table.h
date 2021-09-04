#ifndef INCLUDE_PLASTIC_TABLE_H
#define INCLUDE_PLASTIC_TABLE_H

#include <iostream>

template <typename T>
class PlasticTable : public Table<T>
{
public:
    void create() override;
};

template<typename T>
void PlasticTable<T>::create()
{
    std::cout << "Create plastic table" << std::endl;
}

#endif