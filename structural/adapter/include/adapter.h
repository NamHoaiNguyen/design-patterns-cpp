#ifndef INCLUDE_ADAPTER_H
#define INCLUDE_ADAPTER_H
#pragma once

#include "adaptee.h"
#include "target.h"

#include <memory>

template<typename T>
class Adapter : public Target<T>{
private:
//    template<typename U>
    Adaptee<T> adaptee_;

    std::unique_ptr<Adaptee<T>> adaptee__;

    decltype(auto) translate(T words);

public:
    Adapter() = delete;

//    template<typename U>
    Adapter(Adaptee<T> const& adaptee);

    Adapter(std::unique_ptr<Adaptee<T>> adaptee);

    virtual void send(T words) override;
};

template<typename T>
//template<typename U>
Adapter<T>::Adapter(Adaptee<T> const& adaptee) : adaptee_(adaptee)
{

}

template<typename T>
//template<typename U>
Adapter<T>::Adapter(std::unique_ptr<Adaptee<T>> adaptee) : adaptee__(std::move(adaptee))
{

}

template<typename T>
void Adapter<T>::send(T words)
{
    std::cout << "Reading words " << std::endl;
    std::cout << words << std::endl;
    T new_words = this->translate(words);
    std::cout << "Sending words " << std::endl;
    adaptee_.receive(new_words);
}

template<typename T>
decltype(auto) Adapter<T>::translate(T words)
{
    std::cout << "Translated " << std::endl;
    return "Hello";
}

#endif