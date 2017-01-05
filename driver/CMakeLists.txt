cmake_minimum_required(VERSION 3.3)
project(Assignment3Driver)

include_directories("C:\\Users\\Seth\\Desktop\\WCCC\\CPT 180 - C++ Programming\\Assignment3\\lib")
link_directories("C:\\Users\\Seth\\Desktop\\WCCC\\CPT 180 - C++ Programming\\Assignment3\\lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Assignment3Driver ${SOURCE_FILES})
target_link_libraries(Assignment3Driver Assignment3)