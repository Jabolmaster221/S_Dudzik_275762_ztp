#include "C:\Users\sebci\CLionProjects\Dudzik_275762_ztp\lista1\lib\hello\hello.h"
#include <nlohmann/json.hpp>
#include <iostream>



int main() {
    hello_world();

    nlohmann::json j;
    j["student"]="Dudzik";
    j["indeks"]="275762";
    j["status"]="json wykonany!";

    std::cout << j.dump(4) << std::endl;
    return 0;
}