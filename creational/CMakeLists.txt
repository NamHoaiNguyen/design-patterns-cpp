cmake_minimum_required (VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

set (singleton_include_dir singleton/include)

set (singleton_source 
    singleton/src/main.cc
)

set (SOURCES ${singleton_include_dir} ${singleton_source})

set (abstract_factory_include_dir 
    Abstract_Factory/include
)

set (abstract_factory_source 
    Abstract_Factory/src/main.cc
)

set (builder_include_dir)

set (builder_source 
    builder/src/main.cc
)

set (factory_include_dir 
    Factory_Method/factory/include/factory_method.h
    Factory_Method/pizza_store/newyork/ny_store.h
    Factory_Method/pizza_store/oakland/oakland_store.h
    Factory_Method/pizza_store/pizza.h
)

set (factory_source Factory_Method/main.cc)

set (prototype_include_dir prototype/include)

set (prototype_source prototype/src/main.cc)

add_executable(singleton ${singleton_source})
target_include_directories(singleton PUBLIC ${singleton_include_dir})


add_executable(abstract_factory ${abstract_factory_source})
target_include_directories(abstract_factory PUBLIC ${abstract_factory_include_dir})


add_executable(builder 
    ${builder_source} 
    ${builder_include_dir}
)

add_executable(factory ${factory_source})
target_include_directories(factory PUBLIC ${factory_include_dir})

add_executable(prototype ${prototype_source})
target_include_directories(prototype PUBLIC ${prototype_include_dir})


