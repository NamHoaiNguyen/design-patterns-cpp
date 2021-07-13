#ifndef account_service
#define account_service

template<typename T>
class AccountService {
public:
    AccountService() = default;
    decltype(auto) get_account(T&& email);
};

template<typename T>
decltype(auto) AccountService<T>::get_account(T&& email) {
    std::cout << "Getting the account" << std::endl;
}

#endif