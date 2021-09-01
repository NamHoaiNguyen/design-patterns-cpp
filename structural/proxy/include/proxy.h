#ifndef INCLUDE_PROXY_H
#define INCLUDE_PROXY_H

#include "subject.h"
#include "real_object.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>

template<typename T>
class Proxy : public Subject<T> {
private:
    T name_;
    T role_;
    std::unique_ptr<Subject<T>> real_object_;

public:
    Proxy() = delete;

    explicit Proxy(const T&name, const T& role);

    ~Proxy() = default;

    void load() override;

    void insert() override;

    bool compare(T role_);
};

template<typename T>
Proxy<T>::Proxy(const T&name, const T& role)
{
    role_ = role;
    real_object_ = std::make_unique<RealObject<T>>(name);
}

template<typename T>
void Proxy<T>::load()
{
    std::cout << "load real object in primary template" << std::endl;
    real_object_->load();
}

template<typename T>
void Proxy<T>::insert()
{
    std::cout << "insert real object in primary template" << std::endl;

    if (compare(this->role_)) {
        real_object_->insert();
    } else {
        std::cout << "insert real object failed in primary template" << std::endl;
    }

    std::cout << "\n";
}

template<typename T>
bool Proxy<T>::compare(T role_)
{
    std::cout << "String compare in primary template" << std::endl;

    return role_ ? true : false;
}


/*Test specialization*/
template<>
class Proxy<std::string> : public Subject<std::string>{
private:
    std::string name_;
    std::string role_;
    std::unique_ptr<Subject<std::string>> real_object_;

public:

    Proxy() = delete;

    /*test SFINAE*/
    template<typename T_, typename = std::enable_if_t<std::is_same<T_, std::string>::value>>
    explicit Proxy(const T_& name, const T_& role)
    {
        role_ = role;
        real_object_ = std::make_unique<RealObject<std::string>>(name);
    }

    ~Proxy() = default;

    void load() override;

    void insert() override;

    bool string_compare(std::string role_);
};


void Proxy<std::string>::load()
{
    std::cout << "load proxy object in template specialization(string)" << std::endl;
    real_object_->load();
}

void Proxy<std::string>::insert()
{   
    std::cout << "insert proxy object in template specialization(string)" << std::endl;

    if (string_compare(this->role_)) {
        real_object_->insert();
    } else {
        std::cout << "insert proxy object failed in template specialization(string)" << std::endl;
    }

    std::cout << "\n";
}

bool Proxy<std::string>::string_compare(std::string role_)
{
    std::cout << "Proxy: string compare in template specialization(string)" << std::endl;
    
    auto role_temp = role_;
    std::for_each(role_temp.begin(), role_temp.end(), [](auto &c) {
        c = ::tolower(c);
    });
    
    return !role_temp.compare("admin") ? true : false;
}

#endif