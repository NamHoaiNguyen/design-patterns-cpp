set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

set (creational_include_dir "/home/hoainam/self-learn/design-patterns-cpp/creational")

# include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(abstract Abstract_Factory/src/main.cc)

target_include_directories(abstract PRIVATE ${creational_include_dir}/Abstract_Factory/include)

add_executable(builder builder/src/main.cc)

target_include_directories(builder PRIVATE ${creational_include_dir}/builder/include)

add_executable(factory Factory_Method/main.cc)

target_include_directories(factory PRIVATE ${creational_include_dir}/Factory_Method/include)

add_executable(prototype prototype/src/main.cc)

target_include_directories(prototype PRIVATE ${creational_include_dir}/prototype/include)

add_executable(singleton singleton/src/main.cc)

target_include_directories(singleton PRIVATE ${creational_include_dir}/singleton/include)