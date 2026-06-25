cmake_minimum_required(VERSION 4.0)
project(Dudzik_275762_ztp)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_CXX_STANDARD 26)

find_package(Threads REQUIRED)
include(FetchContent)

# Pobranie Json-a
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)

FetchContent_MakeAvailable(json)

# Tworzenie biblioteki
add_library(hello lib/hello/hello.cpp)

# Wskazujemy, gdzie znajdują się nagłówki (.h) dla tej biblioteki.
target_include_directories(hello PUBLIC lib/hello)

# Program 1 - Budowa
add_executable(prog1 src/prog1/main.cpp)
# Linkowanie biblioteki hello do programu prog1
target_link_libraries(prog1 PRIVATE hello Threads::Threads)

# Program 2 - Budowa
add_executable(prog2 src/prog2/main.cpp)
# Linkowanie biblioteki hello do programu prog2
target_link_libraries(prog2 PRIVATE hello nlohmann_json::nlohmann_json)
