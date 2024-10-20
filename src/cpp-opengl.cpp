#include <iostream>
#include "Window.h"

int main() {
    window win(600, 600, "Hello World");
    if(win.init()) {

    }
    std::cout << "Hello CMake." << std::endl;
    return 0;
}
