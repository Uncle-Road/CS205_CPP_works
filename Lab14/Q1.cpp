#include <iostream>
#include <string>

using namespace std;

template<typename T>
T Max(T one, T two);

int main() {
    int i_one = 5, i_two = 3;
    cout << "The max of two integers " << i_one << " and " << i_two << " is "<< Max(i_one, i_two) << endl;

    double d_one = 5.6, d_two = 10.3;
    cout << "The max of two doubles " << d_one << " and " << d_two << " is "<< Max(d_one, d_two) << endl;

    string s_one = "Hello", s_two = "World";
    cout << "The max of two strings " << s_one << " and " << s_two << " is "<< Max(s_one, s_two) << endl;

    return 0;
}

//Make a template out of this function. Don't forget the return type.
template<typename T>
T Max(T one, T two) {
    T biggest;
    if (one < two) {
        biggest = two;
    } else {
        biggest = one;
    }
    return biggest;
}
