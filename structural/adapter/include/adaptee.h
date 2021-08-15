#ifndef INCLUDE_ADAPTEE_H
#define INCLUDE_ADAPTAE_H
#pragma once

#include <iostream>

template<typename T>
class Adaptee {    
public:
    Adaptee() = default;

    decltype(auto) receive(T words);
};

template<typename T>
decltype(auto) Adaptee<T>::receive(T words)
{
    std::cout << "Receive words from adapter " << std::endl;
    std::cout << words << std::endl; 
}

#endif