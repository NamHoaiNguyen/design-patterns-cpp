#ifndef INCLUDE_CHECKING_ACCOUNT_H
#define INCLUDE_CHECKING_ACCOUNT_H

template<typename T>
class CheckingAccount {
    private:

    public:
        CheckingAccount() = default;

        ~CheckingAccount() = default;

        void openAccount() override;
};

template<typename T>
void CheckingAccount<T>::openAccount() {
    std::cout << "Checking account" << std::endl;
}

#endif