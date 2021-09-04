#ifndef INCLUDE_ABSTRACT_H
#define INCLUDE_ABSTRACT_H

#include "chair.h"
#include "table.h"

#include <memory>

template<typename T>
class FurnitureAbstract 
{
public:
    ~FurnitureAbstract () = default;

    virtual std::unique_ptr<Chair<T>> create_chair() = 0;
    
    virtual std::unique_ptr<Table<T>> create_table() = 0;
};

#endif