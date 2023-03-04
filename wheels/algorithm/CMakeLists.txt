
include_directories(include)

add_library(list ./list.cpp ./universal_link_list.cpp)
add_executable(util_test test/util_test.cpp)
add_executable(search_test test/search_test.cpp)
add_executable(sort_test test/sort_test.cpp)