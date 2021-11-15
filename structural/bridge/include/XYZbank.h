#ifndef INCLUDE_XYZBANK_H
#define INCLUDE_XYZBANK_H

#include <memory>

template<typename T>
class XYZbank {
    private:
        Account account_;

    public:
        Bank() = delete;

        explicit Bank(std::unique_ptr<Account<T>> &account) : account_((account)) {

        }
        
        ~Bank() = default;

        void openAccount() override;
};

template<typename T>
void XYZbank<T>::openAccount() {
     std::cout << "XYZ bank" << std::end;   
}

#endif