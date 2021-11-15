#include "adaptee.h"
#include "adapter.h"
#include "target.h"

#include <memory>
#include <string>
#include <iostream>

int main()
{
    Adaptee<std::string> adaptee;
    std::unique_ptr<Target<std::string>> target = 
    std::make_unique<Adapter<std::string>>(adaptee);
    target->send("Xin chao");

    /*Test about using pass unique_ptr "adaptee" to "adapter" constructor*/
    std::unique_ptr<Target<std::string>> target_2 = 
    std::make_unique<Adapter<std::string>>(std::make_unique<Adaptee<std::string>>());
    target_2->send("Xin chao");

    return 0;
}