#include "../include/account_service.h"
#include "../include/observer/mailer.h"
#include "../include/observer/message.h"

#include <iostream>
#include <memory>

int main()
{
    std::string test = "test acc 1";
    AccountService<Observer<std::string>> acc1;

    std::shared_ptr<Mailer<std::string>> mail = std::make_shared<Mailer<std::string>>(1, "ham mail");
    std::shared_ptr<Message<std::string>> mess = std::make_shared<Message<std::string>>(2, "ham message");

    /*Double free when using smart pointer and convert to raw pointer*/
    // acc1.Attach(mail.get());
    acc1.Attach(mail);
    acc1.Attach(mess);
    acc1.login();
    acc1.Detach(mail);
    acc1.login();
    return 0;
}