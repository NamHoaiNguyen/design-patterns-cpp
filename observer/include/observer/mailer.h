#ifndef mailer
#define mailer 

#include "observer.h"

template<typename T>
class Mailer : public Observer
{
private:
	int id;
    T test;

public:
    Mailer(int id, T const& test);
    virtual void Update() override;

    template<typename S>
    friend bool operator== (const Mailer<S>& mail1, const Mailer<S>& mail2);
};

template<typename T>
Mailer<T>::Mailer(int id, T const& test) : id{id}, test{test}
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
