#ifndef INCLUDE_PROTOTYPE_H
#define INCLUDE_PROTOTYPE_H

#include <iostream>
#include <memory>

template<typename T>
class Prototype {
public:
    Prototype() = default;

    virtual void print_string(std::ostream& out) const = 0;

    friend std::ostream& operator<< (std::ostream& out, const Prototype& A)
    {
        A.print_string(out);
        return out;
    }

    virtual std::shared_ptr<Prototype<T>> clone() = 0;

};

#endif