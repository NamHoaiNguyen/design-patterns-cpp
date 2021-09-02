SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable(abstract Abstract_Factory/src/main.cc)

add_executable(builder builder/src/main.cc)

add_executable(factory Factory_Method/main.cc)

add_executable(prototype prototype/src/main.cc)

add_executable(singleton singleton/main.cc)