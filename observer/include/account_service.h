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
    std::vector<std::shared_ptr<T>> observers;
    // std::vector<T*> observers;
    User user;

public:
    AccountService();
    ~AccountService();
    AccountService(const AccountService<T> &account);
    AccountService &operator= (const AccountService<T> &account);

    virtual void Attach(std::shared_ptr<T> obs) override;
    virtual void Detach(std::shared_ptr<T> obs) override;
    virtual void Notify() override;

    void login();
};


template<typename T>
AccountService<T>::AccountService() 
{

}

template<typename T>
AccountService<T>::~AccountService()
{
    // for (auto &elem : observers) {
    //     delete elem;
    // }
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

    // for (auto &elem : observers) {
    //     if (elem != NULL)  delete elem;
    // }

    // for (auto &elem : observers) {
    //     // elem = new T();
    //     elem = std::make_shared<T>();
    // }

    observers = account.observers;

    return *this;
}

template<typename T>
void AccountService<T>::Attach(std::shared_ptr<T> obs)
{
    /*Note : find vs find_if*/
    auto getId = std::find_if(observers.begin(), observers.end(), [&obs](const auto &elem)
    {
        return obs->id == elem->id;
    });
    if (getId == observers.end()) {
        observers.push_back(obs);
    }
    std::cout << "Test attach method " << std::endl;
}

template<typename T>
void AccountService<T>::Detach(std::shared_ptr<T> obs)
{
    /*Note : find vs find_if*/
    auto getId = std::find_if(observers.begin(), observers.end(), [&obs](const auto &elem)
    {
        return obs->id == elem->id;
    });
    if (getId != observers.end()) {
        observers.erase(getId);
    }
    std::cout << "Test detach method " << std::endl;
}

template<typename T>
void AccountService<T>::Notify()
{
	for (auto &elem : observers) {
		elem->Update();
	}
}

template<typename T>
void AccountService<T>::login()
{
    std::cout << "Login is handled " << std::endl; 
    Notify();
}

#endif
