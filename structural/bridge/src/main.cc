#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "Bank.h"
#include "ABCbank.h"
#include "XYZbank.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    auto checking_acc = std::make_unique<CheckingAccount<std::string>>();
    auto abcbank_ = std::make_unique<ABCbank<std::string>>(checking_acc);
    abcbank_->openAccount();

    auto saving_acc = std::make_unique<CheckingAccount<std::string>>();
    auto xyzbank_ = std::make_unique<XYZbank<std::string>>(checking_acc);


    return 0;
}