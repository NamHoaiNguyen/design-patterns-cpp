#include <iostream>
#include <string>

#include "ShopFacade.h"

int main()
{
    auto FacadePattern = ShopFacade<std::string, std::string, std::string, std::string, std::string>::get_instance();
    FacadePattern->buyProductByCashWithFreeShipping("namhoainguyen@gmail.com");

    return 0;
}