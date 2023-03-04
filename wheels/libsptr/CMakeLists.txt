cmake_minimum_required(VERSION 2.8)

set(SRC_SCOPED
    scoped_array.hpp
    scoped_ptr.hpp
)

set(SRC_SHARED
    shared_array.hpp
    shared_ptr.hpp
    weak_ptr.hpp
)


add_executable(scoped_test scoped_test.cpp ${SRC_SCOPED})
add_executable(shared_test shared_test.cpp ${SRC_SHARED})