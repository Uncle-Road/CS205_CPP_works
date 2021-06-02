#include "Complex.h"
#include "Number.h"
#include <iostream>

using namespace std;

int main() {
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a - 2 is " << a - 2 << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * a is " << 2 * a << endl;
    Complex c = b;
    cout << "b==c is " << (b == c) << endl;
    cout << "b!=c is " << (b != c) << endl;
    cout << "a==c is " << (a == c) << endl << endl;
    Complex d;
    cout << "Enter a complex number : " << endl;
    cin >> d;
    
    cout << "d is " << d << endl<<endl;

    Number n1(20);
    Number n2 = n1++;
    cout << n1 << endl;
    cout << n2 << endl;
    Number n3 = n2--;
    cout << n2 << endl;
    cout << n3 << endl;
    Number n4 = ++n3;
    cout << n3 << endl;
    cout << n4 << endl;
    Number n5 = --n4;
    cout << n4 << endl;
    cout << n5 << endl;

    return 0;
}
