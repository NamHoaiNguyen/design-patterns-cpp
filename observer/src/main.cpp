#include "../include/account_service.h"
#include "../include/observer/mailer.h"

#include <iostream>

int main()
{
    std::string test = "test acc 1";
    AccountServer<Mailer<std::string>> acc1();
    AccountServer<Mailer<std::string>> acc2();
    // acc1 = acc2;

    return 0;
}