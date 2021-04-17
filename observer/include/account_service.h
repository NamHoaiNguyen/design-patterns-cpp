#ifndef observer_accountServer
#define observer_accountServer

#include "observer/observer.h"
#include "subject.h"
#include "user.h"

#include <algorithm>    
#include <iostream>
#include <vector>

template<typename T>
class AccountServer : public Subject<T>
{
private:
    // std::vector<std::shared_ptr<T>> observers;
    std::vector<T*> observers;
    User user;

public:
    AccountServer();
    virtual void Attach(T* observer) override;
    virtual void Detach(T* observer) override;
    virtual void Notify() override;

    AccountServer(const AccountServer<T> &accountServer);
    AccountServer &operator= (const AccountServer<T> &account);
};

template<typename T>
AccountServer<T>::AccountServer() 
{

}

template<typename T>
AccountServer<T>& AccountServer<T>::operator=(const AccountServer<T> &account)
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
void AccountServer<T>::Attach(T* observer)
{
    /*stf::find get error when deduce type*/
    /*
    if (std::find(observers.begin(), observers.end(), *observer) == observers.end()) {
        observers.push_back(observer);
    }
    */
    std::vector<Observer *> test;
    Observer *abc;
    std::vector<T *>::iterator it;
    
    if (std::find(observers.begin(), observers.end(), it) == test.end()) {
        return;
    }
   
}

template<typename T>
void AccountServer<T>::Detach(T* observer)
{
    // if (std::find(observers.begin(), observers.end(), observer) != observers.end()) {
    //     observers.erase(observer);
    // }
    std::cout << "Check ham detach " << std::endl;
}

template<typename T>
void AccountServer<T>::Notify()
{
    for (auto *elem : observers) {
        elem.Update(user);
    }
}

#endif