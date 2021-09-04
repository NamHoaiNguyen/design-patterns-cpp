#ifndef INCLUDE_WOOD_CHAIR_H
#define INCLUDE_WOOD_CHAIR_H

#include <iostream>

template <typename T>
class WoodChair : public Chair<T> 
{
public:
    WoodChair() = default;

    void create() override;
};

template<typename T>
void WoodChair<T>::create()
{
    std::cout << "Create wood chair" << std::endl;
}

#endif