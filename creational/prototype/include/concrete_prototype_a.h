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

    virtual void print_string() override;

    friend std::ostream& operator<< (std::ostream& out, const ConcretePrototypeA<T>& A)
    {
     //   out << "Prototype[os = " << A.os_ << ", office " << A.office_ << ", browser " << A.browser_ << "]" << std::endl;
        out << "Deo hieu kieu gi" << std::endl;
        return out; 
    }
};

template<typename T>
ConcretePrototypeA<T>::ConcretePrototypeA(T&& os, T&& office, T&& browser) : os_(std::forward<T>(os)), 
                                                                             office_(std::forward<T>(office)), 
                                                                             browser_(std::forward<T>(browser))
{

}

template<typename T>
std::shared_ptr<Prototype<T>> ConcretePrototypeA<T>::clone()
{
    return std::make_shared<ConcretePrototypeB<T>>();
}

template<typename T>
void ConcretePrototypeA<T>::print_string()
{
    std::cout << "Prototype[os = " << os_ << ", office " << office_ << ", browser " << browser_ << "]" << std::endl;
}

// template<typename T>
// std::ostream& operator<< (std::ostream& out, const ConcretePrototypeA<T>& A)
// {
//     out << "Prototype[os = " << A.os_ << ", office " << A.office_ << ", browser " << A.browser_ << "]" << std::endl;

//     return out;
// }

#endif