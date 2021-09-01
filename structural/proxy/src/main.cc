#include "../include/proxy.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    /*template specialization*/
    std::string name_1 = "user1";
    std::string admin_1 = "admin";
    std::unique_ptr<Proxy<std::string>> admin = std::make_unique<Proxy<std::string>>(name_1, admin_1);
    admin->load();
    admin->insert();

    std::string name_2 = "user2";
    std::string user_2 = "user";
    std::unique_ptr<Proxy<std::string>> user2 = std::make_unique<Proxy<std::string>>(name_2, user_2);
    user2->load();
    user2->insert(); 

    /*primary template*/
    int name_3 = 2;
    int user_3 = 1;
    std::unique_ptr<Proxy<int>> user3 = std::make_unique<Proxy<int>>(name_3, user_3);
    user3->load();
    user3->insert(); 

    int name_4 = 3;
    int user_4 = 0;
    std::unique_ptr<Proxy<int>> user4 = std::make_unique<Proxy<int>>(name_4, user_4);
    user4->load();
    user4->insert(); 

    return 0;
}