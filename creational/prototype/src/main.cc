#include "../include/prototype.h"
#include "../include/concrete_prototype_a.h"
#include "../include/concrete_prototype_b.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    auto proto = std::make_shared<ConcretePrototypeA<std::string>>("Linux", "Word", "Chrome");
    auto proto_1 = proto->clone();

    std::cout << *proto_1.get() << std::endl;

    return 0;
}