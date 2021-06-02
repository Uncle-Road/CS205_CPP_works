#include "Rectangle.h"
#include <iostream>
#include <iomanip>

Rectangle::Rectangle() {

}

Rectangle::Rectangle(double w, double h) : width(w), height(h) {

}

double Rectangle::getArea() {
    return this->width * this->height;
}

double Rectangle::getPerimeter() {
    return 2 * (this->width + this->height);
}

void Rectangle::display() {
    std::cout << "-------------" << std::endl;
    std::cout << "Width:      " << std::setiosflags(std::ios::left) << this->width << std::endl;
    std::cout << "Height:     " << std::setiosflags(std::ios::left) << this->height << std::endl;
    std::cout << "Area:       " << std::setiosflags(std::ios::left) << this->getArea() << std::endl;
    std::cout << "Perimeter:  " << std::setiosflags(std::ios::left) << this->getPerimeter() << std::endl;
}