cmake_minimum_required(VERSION 3.19)

project(design-pattern VERSION 1.0)

set(CMAKE_XXX_STANDARD 17)
set(CMAKE_XXX_STANDARD_REQUIRED True)

add_subdirectory(behavioral)

add_subdirectory(creational)

add_subdirectory(structural)

# add_executable(factory creational/factory/Factory_Method/main.cpp)