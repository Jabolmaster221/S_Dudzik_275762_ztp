cmake_minimum_required(VERSION 4.0)
project(Dudzik_275762_ztp)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_CXX_STANDARD 26)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -Wextra")

add_executable(zad1 zad1.cpp)
add_executable(zad2 zad2.cpp)
add_executable(zad3 zad3.cpp)

add_custom_target(generate_asm
        COMMAND ${CMAKE_CXX_COMPILER} -S -masm=intel -O0 ${CMAKE_CURRENT_SOURCE_DIR}/zad2_asm.cpp -o ${CMAKE_CURRENT_BINARY_DIR}/zad2_asm.s
        COMMENT "Generowanie kodu asemblera dla zadanie2_asm.cpp..."
)