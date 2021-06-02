#include <iostream>
#include <math.h>

using namespace std;

class CStereoShape {
private:
    inline static int numberOfObject = 0;

public:
    CStereoShape() {
        numberOfObject++;
    }

    virtual double GetArea() {
        cout << "CStereoShape::GetArea()" << endl;
        return 0.0;
    }

    virtual double GetVolume() {
        cout << "CStereoShape::GetVolume()" << endl;
        return 0.0;
    }

    virtual void Show() {
        cout << "CStereoShape::Show()" << endl;
    }

    static int GetNumOfObject() {
        return numberOfObject;
    }
};

class CCube : public CStereoShape {
public:
    double length;
    double width;
    double height;

    CCube() : length(0), width(0), height(0) {}

    CCube(double length, double width, double height)
            : length(length), width(width), height(height) {}

    CCube(const CCube &c) : length(c.length), width(c.width), height(c.height) {}

    double GetArea() override {
        double area = 2 * (length * width + length * height + width * height);
        return area;
    }

    double GetVolume() override {
        double volume = length * width * height;
        return volume;
    }

    void Show() override {
        cout << "For Cube" << endl
             << "length: " << length << ","
             << "width: " << width << ","
             << "height: " << height << endl
             << "area: " << GetArea() << endl
             << "volume: " << GetVolume() << endl;
    }
};

class CSphere : public CStereoShape {
public:
    double radius;

    CSphere() : radius(0) {}

    CSphere(double radius) : radius(radius) {}

    CSphere(const CSphere &c) : radius(c.radius) {}

    double GetArea() override {
        return 4 * radius * radius * M_PI;
    }

    double GetVolume() override {
        return 4.0 / 3.0 * M_PI * radius * radius * radius;
    }

    void Show() override {
        cout << "For Sphere" << endl
             << "radius: " << radius << endl
             << "area: " << GetArea() << endl
             << "volume: " << GetVolume() << endl;
    }
};


