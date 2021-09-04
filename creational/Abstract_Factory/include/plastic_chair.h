#ifndef INCLUDE_PLASTIC_CHAIR_H
#define INCLUDE_PLASTIC_CHAIR_H

#include <iostream>

template <typename T>
class PlasticChair : public Chair<T>
{
public:
    PlasticChair() = default;

    void create() override;
};

template<typename T>
void PlasticChair<T>::create()
{
    std::cout << "Create plastic chair" << std::endl;
}


#endif