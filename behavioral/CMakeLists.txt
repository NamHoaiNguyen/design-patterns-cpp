set (behavioral_include_dir "/home/hoainam/self-learn/design-patterns-cpp/behavioral")
# set(behavioral_include_dir "{CMAKE_CURRENT_SOURCE_DIR}/behavioral")

add_executable(chain chain_of_responsibility/src/main.cc)

target_include_directories(chain PRIVATE ${behavioral_include_dir}/chain/include)

add_executable(command command/src/main.cc)

target_include_directories(command PRIVATE ${behavioral_include_dir}/command/include)

add_executable(interpreter interpreter/src/main.cc)

target_include_directories(interpreter PRIVATE ${behavioral_include_dir}/interpreter/include)

add_executable(iterator iterator/src/main.cc)

target_include_directories(iterator PRIVATE ${behavioral_include_dir}/iterator/include)

add_executable(mediator mediator/src/main.cc)

target_include_directories(mediator PRIVATE ${behavioral_include_dir}/mediator/include)

add_executable(memento memento/src/main.cc)

target_include_directories(memento PRIVATE ${behavioral_include_dir}/memento/include)

add_executable(observer observer/src/main.cc)

target_include_directories(observer PRIVATE ${behavioral_include_dir}/observer/include)

add_executable(state state/src/main.cc)

target_include_directories(state PRIVATE ${behavioral_include_dir}/state/include)

add_executable(strategy strategy/src/main.cc)

target_include_directories(strategy PRIVATE ${behavioral_include_dir}/strategy/include)

add_executable(template template_method/src/main.cc)

target_include_directories(template PRIVATE ${behavioral_include_dir}/template/include)

add_executable(visitor visitor/src/main.cc)

target_include_directories(template PRIVATE ${behavioral_include_dir}/visitor/include)

