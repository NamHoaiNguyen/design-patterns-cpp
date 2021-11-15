#ifndef INCLUDE_SAVING_ACCOUNT_H
#define INCLUDE_SAVING_ACCOUNT_H

#include<iostream>

template<typename T>
class SavingAccount : public Account<T> {
    private:

    public:
        SavingAccount() = default;

        ~SavingAccount() = default;

        void openAccount() override;
};

template<typename T>
void SavingAccount<T>::openAccount() {
    std::cout << "saving account" << std::endl;
}

#endif