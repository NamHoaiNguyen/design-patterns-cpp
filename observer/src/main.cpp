#include "../include/account_service.h"
#include "../include/observer/mailer.h"

#include <iostream>

// template<typename T>
// AccountService<T> CreateAccount()
// {
//     AccountService<T> account = new AccountService<T>();
//     account.attach(new Mailer<std::string>());
//     return account;
// }

int main()
{
    std::string test = "test acc 1";
    AccountService<Mailer<std::string>> acc1();
    AccountService<Mailer<std::string>> acc2();
    // acc1 = acc2;

    // AccountService<std::string> account = CreateAccount<std::string>();
    return 0;
}