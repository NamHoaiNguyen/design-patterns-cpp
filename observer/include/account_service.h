#ifndef accountServer
#define accountServer

#include "observer.h"
#include "subject.h"

#include<vector>

template<typename T>
class AccountServer : public Subject<T>
{
private:
    // std::vector<T> observers;
    // std::vector<std::shared_ptr<Observer<T>>> observers;
    std::vector<T*> observers;
public:
    AccountServer();
    virtual void attach() override;
    virtual void detach() override;
    virtual void notify() override;

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
void AccountServer<T>::attach()
{

}

template<typename T>
void AccountServer<T>::detach()
{

}

template<typename T>
void AccountServer<T>::notify()
{

}

#endif