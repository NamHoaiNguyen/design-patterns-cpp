#include "../include/prototype.h"
#include "../include/concrete_prototype_a.h"
#include "../include/concrete_prototype_b.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::shared_ptr<Prototype<std::string>> proto = std::make_shared<ConcretePrototypeA<std::string>>("Linux", "Word", "Chrome");
    std::shared_ptr<Prototype<std::string>> proto_1 = proto->clone();

    // proto->print_string();
    // proto_1->print_string();

    std::cout << proto << std::endl;
    
    return 0;
}