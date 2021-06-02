#include <iostream>
#include "shape.cpp"

using namespace std;

int main() {
    CStereoShape *p;
    CCube a_cube(4.0, 5.0, 6.0);
    CSphere c_sphere(7.9);

    p = &a_cube;
    p->Show();
    cout << endl;

    p = &c_sphere;
    p->Show();
    cout<<endl;

    cout<< CStereoShape::GetNumOfObject() << " objects are created."<< endl;

    return 0;
}
