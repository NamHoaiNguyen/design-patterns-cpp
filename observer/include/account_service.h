#include <subject.h>

template<typename T>
class AccountServer : public Subject<T>
{
    AccountServer();
    virtual void attach() override;
    virtual void detach() override;
    virtual void notify() override;
};

template<typename T>
AccountServer<T>::AccountServer()
{

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