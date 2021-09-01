#ifndef INCLUDE_REAL_OBJECT_H
#define INCLUDE_REAL_OBJECT_H

#include "subject.h"

#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
class RealObject : public Subject<T> {
private:
    T name_;

public:
    RealObject() = delete;

    explicit RealObject(const T& name) 
    {
        name_ = name;
    }

    ~RealObject() = default;

    void load() override;

    void insert() override;
};

template<typename T>
void RealObject<T>::load()
{
    std::cout << name_ << " load real object primary template" << std::endl;
}

template<typename T>
void RealObject<T>::insert()
{
    std::cout << name_ << " insert real object primary template" << std::endl;
}

/*test specialization*/
template<>
class RealObject<std::string> : public Subject<std::string> {
private:
    std::string name_;

public: 
    RealObject() = default;
    
    template<typename T_, typename = std::enable_if_t<std::is_same<T_, std::string>::value>>  
    explicit RealObject(T_ name)
    {
        name_ = name;
    }

    void load() override;

    void insert() override;
};

void RealObject<std::string>::load()
{
    std::cout << name_ << " load real object template specialization(string)" << std::endl;
}

void RealObject<std::string>::insert()
{
    std::cout << name_ << " insert real object template specialization(string)" << std::endl;
}

#endif