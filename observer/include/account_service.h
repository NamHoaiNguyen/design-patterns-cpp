#ifndef observer_AccountService
#define observer_AccountService

#include "observer/observer.h"
#include "subject.h"
#include "user.h"

#include <algorithm>    
#include <iostream>
#include <vector>

template<typename T>
class AccountService : public Subject<T>
{
private:
    // std::vector<std::shared_ptr<T>> observers;
    std::vector<T*> observers;
    User user;

public:
    AccountService();
    ~AccountService();
    virtual void Attach(T* observer) override;
    virtual void Detach(T* observer) override;
    virtual void Notify() override;

    void login();

    AccountService(const AccountService<T> &account);
    AccountService &operator= (const AccountService<T> &account);
};


template<typename T>
AccountService<T>::AccountService() 
{

}

template<typename T>
AccountService<T>::~AccountService()
{
    for (auto &elem : observers) {
        delete elem;
    }
}

template<typename T>
AccountService<T>::AccountService(const AccountService<T> &account)
{
    observers = account.observers;
}

template<typename T>
AccountService<T>& AccountService<T>::operator=(const AccountService<T> &account)
{
    if (this == &account) 
        return *this;

    for (auto &elem : observers) {
        if (elem != NULL)  delete elem;
    }

    for (auto &elem : observers) {
        elem = new T();
    }

    observers = account.observers;

    return *this;
}

template<typename T>
void AccountService<T>::Attach(T* observer)
{
    /*stf::find get error when deduce type*/
    /*
    if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
        observers.push_back(observer);
    }
    */
   T* test;
    std::cout << "Test attach method " << std::endl;
    observers.push_back(test);
}

template<typename T>
void AccountService<T>::Detach(T* observer)
{
    // if (std::find(observers.begin(), observers.end(), observer) != observers.end()) {
    //     observers.erase(observer);
    // }
    std::cout << "Test detach method " << std::endl;
    observers.erase();
}

template<typename T>
void AccountService<T>::Notify()
{
    // for (auto &elem : observers) {
    //     elem->Update(user);
    // }
}

template<typename T>
void AccountService<T>::login()
{
    Notify();
}

#endif