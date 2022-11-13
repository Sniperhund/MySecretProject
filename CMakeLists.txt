cmake_minimum_required(VERSION 3.22)
project(MySecretProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(MySecretProject main.cpp src/Util.cpp src/Util.h src/Attacks.cpp src/Attacks.h)
target_link_libraries(MySecretProject -static)