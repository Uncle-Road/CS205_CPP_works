#include <iostream>
#include <exception>

using namespace std;

class Exp : public exception {
public:
    string message;
    explicit Exp(string message) : message(std::move(message)) {}
};

void calculateAverage() {
    double sum = 0;
    for (int i = 1; i <= 4; ++i) {
        int it;
        cin >> it;
        if (it < 0 || it > 100) {
            throw Exp("The parameter" + to_string(i) +
                      " is " + to_string(it) +
                      " which out of range(0-100)\n"+
                      "please enter marks for 4 courses:");
        }
        sum += it;
    }
    cout << "The average of the four courses is " << sum / 4 << endl;
}

int main() {
    string line;
    cout << "please enter marks for 4 courses:";
    char a='y';
    while (a=='y') {
        try {
            calculateAverage();
            cout << "Would you want to enter anther marks for 4 courses(y/n)?";
            cin >> a;
            if(a=='n'){
                cout<<"Bye, see you next time";
                return 0;
            }
            if(a=='y'){
                cout << "Please enter marks for 4 courses:";
            }
        } catch (const Exp &e) {
            cerr << e.message << endl;
            cin.ignore(1000, '\n');
        }

    }
}



