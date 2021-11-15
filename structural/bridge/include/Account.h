#ifndef INCLUDE_ACCOUNT_H
#define INCLUDE_ACCOUNT_H

template<typename T>
class Account {
    private:

    public:
        Account() = default;

        ~Account() = default;

        virtual void openAccount() = 0;
};

#endif