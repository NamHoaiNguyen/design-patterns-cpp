#ifndef INCLUDE_CONCRETE_PROTOTYPE_A_H
#define INCLUDE_CONCRETE_PROTOTYPE_A_H

#include "concrete_prototype_b.h"

#include <iostream>
#include <memory>

template<typename T>
class ConcretePrototypeA : public Prototype<T> {
private:
    T os_, office_, browser_;

public:
    ConcretePrototypeA() = default;

    ConcretePrototypeA(T&& os, T&& office, T&& browser);

    virtual std::shared_ptr<Prototype<T>> clone() override;

    virtual void print_string(std::ostream& out) const override;
};

template<typename T>
ConcretePrototypeA<T>::ConcretePrototypeA(T&& os, T&& office, T&& browser) : os_(std::forward<T>(os)), 
                                                                             office_(std::forward<T>(office)), 
                                                                             browser_(std::forward<T>(browser))
{

}


template<typename T>
void ConcretePrototypeA<T>::print_string(std::ostream& out) const
{
    out << "Prototype[os = " << os_ << ", office " << office_ << ", browser " << browser_ << "]" << std::endl;
}

template<typename T>
std::shared_ptr<Prototype<T>> ConcretePrototypeA<T>::clone()
{
    return std::make_shared<ConcretePrototypeA<T>>(*this);
}

#endif