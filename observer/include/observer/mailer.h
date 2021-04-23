#ifndef mailer
#define mailer 

#include "observer.h"

template<typename T>
class Mailer : public Observer<T>
{
private:
    T mailTest;

public:
    Mailer(int id, T const& test);
    virtual void Update() override;

    template<typename S>
    friend bool operator== (const Mailer<S>& mail1, const Mailer<S>& mail2);
    template<typename S, typename U>
    friend bool operator== (const Mailer<S>& mail1, const Mailer<U>& mail2);
};

template<typename T>
Mailer<T>::Mailer(int id, T const& mailTest) : mailTest{mailTest}
{
    this->id = id;
}

template<typename S>
bool operator== (const Mailer<S>& mail1, const Mailer<S>& mail2)
{
    return mail1.id == mail2.id;
}

template<typename S, typename U>
bool operator== (const Mailer<S>& mail1, const Mailer<U>& mail2)
{
    return false;
}

template<typename T>
void Mailer<T>::Update()
{
    std::cout << "Check Id and mailTest " << "'" << this->id << " " << mailTest << "'" << std::endl; 
    std::cout << "User will receive email when logging in " << std::endl;
    return;
}

#endif
