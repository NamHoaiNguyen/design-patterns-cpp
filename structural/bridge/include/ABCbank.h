#ifndef INCLUDE_ABCBANK_H
#define INCLUDE_ABCBANK_H

#include "Account.h"

#include<iostream>
#include<memory>

template<typename T>
class ABCbank : public Bank<T> {
    private:
        std::unique_ptr<Account<T>> account_;

    public:
        ABCbank() = delete;

        explicit ABCbank(std::unique_ptr<Account<T>>& account) : account_(std::move(account)) {

        }

        ~ABCbank() = default;

        void openAccount() override;
};

template<typename T>
void ABCbank<T>::openAccount() {
    std::cout << "Account banking in ABC is ";
    account_->openAccount();
}

#endif