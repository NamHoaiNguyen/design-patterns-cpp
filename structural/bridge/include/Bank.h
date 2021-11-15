#ifndef INCLUDE_ABSTRACTION_H
#define INCLUDE_ABSTRACTION_H

#include "Account.h"

template<typename T>
class Bank {
    // protected:
    //     Account<T> account;      
                
    public:
        Bank() = default;
        
        ~Bank() = default;

        virtual void openAccount() = 0;
};

#endif