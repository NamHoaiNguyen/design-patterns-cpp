#ifndef INCLUDE_CHECKING_ACCOUNT_H
#define INCLUDE_CHECKING_ACCOUNT_H

#include<iostream>

template<typename T>
class CheckingAccount : public Account<T> {
    private:

    public:
        CheckingAccount() = default;

        ~CheckingAccount() = default;

        void openAccount() override;
};

template<typename T>
void CheckingAccount<T>::openAccount() {
    std::cout << "checking account" << std::endl;
}

#endif