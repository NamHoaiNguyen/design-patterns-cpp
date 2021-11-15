#ifndef INCLUDE_XYZBANK_H
#define INCLUDE_XYZBANK_H

#include "Account.h"

#include<iostream>
#include<memory>

template<typename T>
class XYZbank : public Bank<T> {
    private:
        std::unique_ptr<Account<T>> account_;

    public:
        XYZbank() = delete;

        explicit XYZbank(std::unique_ptr<Account<T>>& account) : account_(std::move(account)) {

        }
        
        ~XYZbank() = default;

        void openAccount() override;
};

template<typename T>
void XYZbank<T>::openAccount() {
    std::cout << "Account banking in XYZ is ";
    account_->openAccount();   
}

#endif