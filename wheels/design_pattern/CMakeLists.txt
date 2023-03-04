
include_directories(
  include
)

add_executable(simple_factory_main simple_factory_main.cpp)
add_executable(factory_method_main factory_method_main.cpp)
add_executable(abstract_factory_main abstract_factory_main.cpp)
add_executable(singleton_main singleton_main.cpp)
target_link_libraries(singleton_main pthread)
add_executable(builder_main builder_main.cpp)
add_executable(prototype_main prototype_main.cpp)
