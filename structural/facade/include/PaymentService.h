#ifndef payment_service
#define payment_service

#include <iostream>

template<typename T>
class PaymentService {
public:
    PaymentService() = default;
    decltype(auto) payment_paypal();
    decltype(auto) payment_credit_card();
    decltype(auto) payment_bank_account();
    decltype(auto) payment_cash();
};

template<typename T>
decltype(auto) PaymentService<T>::payment_paypal()
{
    std::cout << "Payment by paypal" << std::endl;
}

template<typename T>
decltype(auto) PaymentService<T>::payment_credit_card()
{
    std::cout << "Payment by credit card" << std::endl;
}

template<typename T>
decltype(auto) PaymentService<T>::payment_bank_account()
{
    std::cout << "Payment by banking account" << std::endl;
}

template<typename T>
decltype(auto) PaymentService<T>::payment_cash()
{
    std::cout << "Payment by cash" << std::endl;
}

#endif