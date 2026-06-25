cmake_minimum_required(VERSION 3.14)
project(tokenizer_project CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tokenizer src/tokenizer.cpp)
target_include_directories(tokenizer PUBLIC src)

add_executable(demo src/main.cpp
        ../obiekty_lista_4/src/Visitor.cpp
        ../obiekty_lista_4/src/Visitor.h
        ../obiekty_lista_4/src/main.cpp
        ../obiekty_lista_4/src/A.cpp
        ../obiekty_lista_4/src/A.h
        ../obiekty_lista_4/src/B.cpp
        ../obiekty_lista_4/src/B.h
        ../lista_3/zad1.cpp
        ../lista_3/zad2.cpp
        ../lista_3/zad2_asm.cpp
        ../lista_3/zad3.cpp)
target_link_libraries(demo PRIVATE tokenizer)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

add_executable(tokenizer_tests tests/test_tokenizer.cpp)

target_link_libraries(tokenizer_tests PRIVATE tokenizer Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(tokenizer_tests)