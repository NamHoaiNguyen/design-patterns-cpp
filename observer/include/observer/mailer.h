#ifndef mailer
#define mailer 

#include "observer.h"

template<typename T>
class Mailer : public Observer
{
private:
    T test;

public:
    Mailer(T const& test);
    virtual void Update() override;

    template<typename S>
    friend bool operator== (const Mailer<S>& mail1, const Mailer<S>& mail2);
};

template<typename T>
Mailer<T>::Mailer(T const& test) : test{test}
{

}

template<typename S>
bool operator== (const Mailer<S>& mail1, const Mailer<S>& mail2)
{
    return &mail1 == &mail2;
}


template<typename T>
void Mailer<T>::Update()
{
    std::cout << "Check ham update ";
    return;
}

#endif