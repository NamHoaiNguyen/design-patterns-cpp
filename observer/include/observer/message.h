#ifndef message
#define message 

#include "observer.h"

template<typename T>
class Message : public Observer<T>
{
private:
    T test;

public:
    Message(int id, T const& test);
    virtual void Update() override;

    template<typename S>
    friend bool operator== (const Message<S>& mail1, const Message<S>& mail2);
    template<typename S, typename U>
    friend bool operator== (const Message<S>& mail1, const Message<U>& mail2);
};

template<typename T>
Message<T>::Message(int id, T const& test) : test{test}
{
    this->id = id;
}

template<typename S>
bool operator== (const Message<S>& mail1, const Message<S>& mail2)
{
    return mail1.id == mail2.id;
}

template<typename S, typename U>
bool operator== (const Message<S>& mail1, const Message<U>& mail2)
{
    return false;
}

template<typename T>
void Message<T>::Update()
{
    std::cout << "User will receive message when logging in " << std::endl;
    return;
}

#endif
