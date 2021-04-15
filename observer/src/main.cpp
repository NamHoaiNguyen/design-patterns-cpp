#include "../include/account_service.h"
#include "../include/mailer.h"

#include <iostream>

int main()
{
    AccountServer<Mailer> acc1;
    AccountServer<Mailer> acc2;
    acc1 = acc2;
    return 0;
}