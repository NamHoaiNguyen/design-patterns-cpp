#ifndef INCLUDE_ABCBANK_H
#define INCLUDE_ABCBANK_H

#include <memory>

template<typename T>
class ABCbank {
    public:
        ABCbank() = delete;

        explicit ABCbank(std::unique_ptr<Account<T>> &account) : account_((account)) {

        }

        ~ABCbank() = default;

        void openAccount() override;
};

template<typename T>
void ABCbank<T>::openAccount() {
    std::cout << "ABC bank" << std::end;
}

#endif