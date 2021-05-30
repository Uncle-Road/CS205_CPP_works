#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>


using namespace std;

const string read_file = "lab_records.csv";

using namespace std;

int main() {
    ifstream fin(read_file);
    //
    if (!fin.good()) {
        cout << "Open fail the file: " << read_file << endl;
        exit(0);
    }

    string line;
    int num = 0;
    int grades[15]{};
    int total = 0;

    while (getline(fin, line)) {
        size_t pos = 0;
        string delimiter = ",";
        int column = 0;
        string token[15];

        while ((pos = line.find(delimiter)) != string::npos) {
            token[column] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            column++;
        }
        token[column] = line;
        num++;
        for (int i = 1; i <= 14; ++i) {
            int it_score = stoi(token[i]);
            grades[i] += it_score;
            total += it_score;
        }
    }
    fin.close();

    double total_average = ((double) total) / num / 14;

    cout << "those labs lower than average scores: " << total_average << endl;

    for (int i = 1; i <= 14; ++i) {
        double average = ((double) grades[i]) / num;
        if (average < total_average) {
            cout << "lab" << i << " average score is: " << average << endl;
        }
    }

    return 0;
}