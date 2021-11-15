set (structural_include_dir "/home/hoainam/self-learn/design-patterns-cpp/structural")

add_executable(adapter adapter/src/main.cc)

target_include_directories(adapter PRIVATE ${structural_include_dir}/adapter/include)

# add_executable(bridge bridge/src/main.cc)

# target_include_directories(bridge PRIVATE ${structural_include_dir}/bridge/include)

add_executable(composite composite/src/main.cc)

target_include_directories(composite PRIVATE ${structural_include_dir}/composite/include)

add_executable(decorator decorator/src/main.cc)

target_include_directories(decorator PRIVATE ${structural_include_dir}/decorator/include)

add_executable(facade facade/src/main.cc)

target_include_directories(facade PRIVATE ${structural_include_dir}/facade/include)

add_executable(flyweight flyweight/src/main.cc)

target_include_directories(flyweight PRIVATE ${structural_include_dir}/flyweight/include)

add_executable(proxy proxy/src/main.cc)

target_include_directories(proxy PRIVATE ${structural_include_dir}/proxy/include)
