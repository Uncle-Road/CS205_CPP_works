#include "candybar.h"

void setCandyBar(CandyBar &cb) {
    cout << "Call the set function of Passing by reference:" << endl;
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb.brand, LEN);
    cout << "Enter weight of a Candy bar: ";
    (cin >> cb.weight).get();
    cout << "Enter calories of a Candy bar: ";
    (cin >> cb.calories).get();
    
}

void setCandyBar(CandyBar *const cb) {
    cout << "Call the set function of Passing by pointer:" << endl;
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb->brand, LEN);
    cout << "Enter weight of a Candy bar: ";
    (cin >> cb->weight).get();
    cout << "Enter calories of a Candy bar: ";
    (cin >> cb->calories).get();
    
}

void showCandyBar(const CandyBar *cb) {
    cout << "Call the show function of Passing by pointer:" << endl;
    cout << "Brand: " << cb->brand << endl;
    cout << "Weight: " << cb->weight << endl;
    cout << "Calories: " << cb->calories << endl;
}

void showCandyBar(const CandyBar &cb) {
    cout << "Call the show function of Passing by reference:" << endl;
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Calories: " << cb.calories << endl;
}