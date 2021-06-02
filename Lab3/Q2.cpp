#include<iostream>

using namespace std;

struct Candybar{
    char name[20];
    float weight;
    int calories; 
};

int main(){
    Candybar bar;
    cout<<"Enter brand name of a Candy bar: ";
    cin.getline(bar.name,20);
    cout<<"Enter weight of he Candy bar:";
    cin>>bar.weight;
    cout<<"ENter calories (an integer value) in the Candy bar: ";
    cin>>bar.calories;

    cout<<"Brand: "<<bar.name<<endl;
    cout <<"Weight: "<<bar.weight<<endl;
    cout << "Calories: " << bar.calories<<endl;
    return 0;
}