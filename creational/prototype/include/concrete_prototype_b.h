#ifndef INCLUDE_CONCRETE_PROTOTYPE_B_H
#define INCLUDE_CONCRETE_PROTOTYPE_B_H

#include "concrete_prototype_a.h"

#include <iostream>
#include <memory>

template<typename T>
class ConcretePrototypeA;

template<typename T>
class ConcretePrototypeB : public Prototype<T> {
private:
    T os_, office_, browser_;

public:
    ConcretePrototypeB() = default;

    ConcretePrototypeB(T&& os, T&& office, T&& browser);

    virtual std::shared_ptr<Prototype<T>> clone() override;

    virtual void print_string() override;

    friend std::ostream& operator<< (std::ostream& out, const ConcretePrototypeB<T>& B)
    {
        out << "Prototype[os = " << B.os_ << ", office " << B.office_ << ", browser " << B.browser_ << "]" << std::endl;

        return out;
    }
};

template<typename T>
ConcretePrototypeB<T>::ConcretePrototypeB(T&& os, T&& office, T&& browser) : os_(std::forward<T>(os)), 
                                                                             office_(std::forward<T>(office)), 
                                                                             browser_(std::forward<T>(browser))
{

}

template<typename T>
std::shared_ptr<Prototype<T>> ConcretePrototypeB<T>::clone()
{
    return std::make_shared<ConcretePrototypeA<T>>();
}

template<typename T>
void ConcretePrototypeB<T>::print_string()
{
    std::cout << "Prototype[os = " << os_ << ", office " << office_ << ", browser " << browser_ << "]" << std::endl;
}

// template<typename T>
// std::ostream& operator<< (std::ostream& out, const ConcretePrototypeB<T>& B)
// {
//     out << "Prototype[os = " << B.os_ << ", office " << B.office_ << ", browser " << B.browser_ << "]" << std::endl;

//     return out;
// }

#endif