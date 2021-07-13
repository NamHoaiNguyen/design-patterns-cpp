#ifndef email_service
#define email_service 

#include <iostream>

template<typename T>
class EmailService {
public:
    EmailService() = default;
    decltype(auto) send_email(T&& mailAddress);
};

template<typename T>
decltype(auto) EmailService<T>::send_email(T&& mailAddress)
{
    std::cout << "Sending an email to " + mailAddress << std::endl;
}

#endif