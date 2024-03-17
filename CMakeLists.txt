cmake_minimum_required(VERSION 3.8)

project(
    laba_3
    LANGUAGES CXX)

set(CMAKe_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(main main.cpp fraction.cpp Complex.cpp nod.cpp)