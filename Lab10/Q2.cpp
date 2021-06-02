#include <iostream>
#include "Rectangle.h"

int main() {
    std::cout << "Rectangle 1" << std::endl;
    Rectangle r1(4, 40);
    r1.display();
    std::cout << "Rectangle 2" << std::endl;
    Rectangle r2(3.5, 35.9);
    r2.display();
    return 0;
}