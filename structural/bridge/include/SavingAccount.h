#ifndef INCLUDE_SAVING_ACCOUNT_H
#define INCLUDE_SAVING_ACCOUNT_H

template<typename T>
class SavingAccount {
    private:

    public:
        SavingAccount() = default;

        ~SavingAccount() = default;

        void openAccount() override;
};

template<typename T>
void SavingAccount<T>::openAccount() {
    std::cout << "Saving account" << std::endl;
}

#endif