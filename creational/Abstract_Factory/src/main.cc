#include "../include/furnitute_factory.h"
#include "../include/material.h"

#include <iostream>

int main()
{
    FunitureFactory<int>::getFactory(Material::PLASTIC); 
    return 0;
}