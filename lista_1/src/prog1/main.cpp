#include "C:\Users\sebci\CLionProjects\Dudzik_275762_ztp\lista1\lib\hello\hello.h"
#include <thread>
#include <iostream>

void thread_function() {
    std::cout << "Watek dziala!" << std::endl;
}
int main() {
    hello_world();

    std::thread t(thread_function);

    t.join();

    return 0;
}