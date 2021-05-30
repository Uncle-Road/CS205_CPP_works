#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student {
    int sid;
    int labs[14];
};

const string store_file = "lab_records.csv"; //Q3 store in filename and Q4 to read

int random(int start, int end);

int generateSID();

Student generateStudent();

int readInt(int start, int end);

vector<Student> Q1();

void Q2(const vector<Student> &students);

void Q3(const vector<Student> &students);

int main() {
    vector<Student> students = Q1();
    cout << endl;

    Q2(students);
    cout << endl;

    Q3(students);
    cout << endl;

    return 0;
}

int random(int start, int end) {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis{};
    int ans = start + dis(gen) % (end - start + 1);
    return ans;
}

int generateSID() {
    int year = random(2000, 2020);
    int num = random(0, 9999);
    int sid = year * 10000 + num;
    return sid;
}

int readInt(int start, int end) {
    try {
        string input;
        cin >> input;
        int i = stoi(input);
        if (i < start || i > end) {
            throw exception();
        }
        return i;
    } catch (const exception &e) {
        cout << "Input is error, end the program." << endl;
        exit(0);
    }
}

Student generateStudent() {
    static set<int> sids{};
    Student s{};
    int sid = generateSID();
    while (sids.find(sid) != sids.end()) {
        sid = generateSID();
    }
    s.sid = sid;
    for (auto &lab : s.labs) {
        lab = random(0, 5);
    }
    return s;
}

vector<Student> Q1() {
    cout << "how many student have: ";
    int n = readInt(1, INT32_MAX);
    vector<Student> students{};
    for (int i = 0; i < n; ++i) {
        students.push_back(generateStudent());
    }
    for (auto &s : students) {
        cout << s.sid << ": ";

        cout << s.labs[0];

        for (int i = 1; i < 14; i++) {
            cout << ", " << s.labs[i];
        }
        cout << endl;
    }
    return students;
}

void Q2(const vector<Student> &students) {
    cout << "those students absent >= 2 times:\n";
    for (auto &s : students) {
        int times = 0;
        for (auto &lab : s.labs) {
            if (lab == 0) {
                times++;
            }
        }
        if (times >= 2) {
            cout << "Student" << s.sid << " had absent " << times << " times." << endl;
        }
    }
}

void Q3(const vector<Student> &students) {
    ofstream fout(store_file);
    if (!fout.good()) {
        cout << "The file: " << store_file << " save failed\n";
        exit(0);
    }
    for (auto &s : students) {
        fout << s.sid << "," << s.labs[0];
        for (int i = 1; i < 14; i++) {
            fout << "," << s.labs[i];
        }
        fout << endl;
    }
    fout.close();
    cout << "store file:" << store_file << " successfully!" << endl;
}
