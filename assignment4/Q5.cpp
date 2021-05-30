#include <iostream>
#include <string>

using namespace std;

int getIndex(string *start, string *end, const string &toSearch) {
    int i = 0;
    while (start != end) {
        if (*start == toSearch) {
            return i;
        }
        i++;
        start++;
    }
    return -1;
}

int main() {
    string operators;
    string commands[] = {"start", "stop", "restart", "reload", "status", "exit"};

    while (true) {
        cout << "> ";
        getline(cin, operators);
        int index = getIndex(begin(commands), end(commands), operators);

        switch (index) {
            case -1:
                cout << "Invalid command" << endl;
                break;
            case 5:
                cout << "program exit" << endl;
                return 0;
            default:
                cout << "command " << operators << " recognized\n";
                break;
        }
    }

}
