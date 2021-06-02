#ifndef CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H
#define CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H


class Rectangle {
private:
    double width = 1;
    double height = 1;
public:
    Rectangle();

    Rectangle(double w, double h);

    double getArea();

    double getPerimeter();

    void display();
};


#endif