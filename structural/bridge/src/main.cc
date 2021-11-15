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
    std::unique_ptr<Account<std::string>> checking_acc = std::make_unique<CheckingAccount<std::string>>();
    std::unique_ptr<Bank<std::string>> abcbank_ = std::make_unique<ABCbank<std::string>>(checking_acc);
    abcbank_->openAccount();

    std::unique_ptr<Account<std::string>> saving_acc = std::make_unique<CheckingAccount<std::string>>();
    std::unique_ptr<Bank<std::string>> xyzbank_ = std::make_unique<XYZbank<std::string>>(saving_acc);
    xyzbank_->openAccount();

    return 0;
}