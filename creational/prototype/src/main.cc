#include "prototype.h"
#include "concrete_prototype_a.h"
#include "concrete_prototype_b.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    auto proto_A = std::make_shared<ConcretePrototypeA<std::string>>("Linux", "Word", "Chrome");
    auto proto_A_1 = proto_A->clone();
    auto proto_B = std::make_shared<ConcretePrototypeB<std::string>>("Linux", "Word", "Chrome");
    auto proto_B_1 = proto_B->clone();

    std::cout << *proto_A_1.get() << std::endl;
    std::cout << *proto_B_1.get() << std::endl;

    return 0;
}