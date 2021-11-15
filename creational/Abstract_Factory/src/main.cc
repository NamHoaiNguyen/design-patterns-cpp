#include "furniture_abstract.h"
#include "furnitute_factory.h"
#include "material.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    /*Test plastic factory*/
    // std::unique_ptr<FurnitureAbstract<std::string>> 
    auto test_platic_factory = FurnitureFactory<std::string>::getFactory(Material::PLASTIC);
    //std::unique_ptr<Chair<std::string>> plastic_chair
    auto plastic_chair= test_platic_factory->create_chair();
    plastic_chair->create();
    //std::unique_ptr<Chair<std::string>> plastic_table
    auto plastic_table= test_platic_factory->create_table();
    plastic_table->create();

    /*Test wood factory*/
    auto test_wood_factory = FurnitureFactory<std::string>::getFactory(Material::WOOD);
    //std::unique_ptr<Chair<std::string>> wood_chair
    auto wood_chair= test_wood_factory->create_chair();
    wood_chair->create();
    //std::unique_ptr<Chair<std::string>> wood_table
    auto wood_table= test_wood_factory->create_table();
    wood_table->create();

    return 0;
}