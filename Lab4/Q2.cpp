#include<iostream>
#include<cmath>
using namespace std;

struct Candybar{
    char name[20];
    float weight;
    int calories; 
};


int main(){
    Candybar *arr;
    arr = new Candybar[3];
    cout << "Please input three CandyBar's information:\n";
    for(int i =0; i < 3; i++){
        cout<<"Enter brand name of a Candy bar: ";
        // cin.get(arr[i].name,20);
        cin.getline(arr[i].name,20);
        cout<<"Enter weight of he Candy bar: ";
        cin>>arr[i].weight;
        cout<<"ENter calories (an integer value) in the Candy bar: ";
        cin>>arr[i].calories;
        cin.get();
    }

    cout << endl <<endl;
    cout << "Displaying the CamdyBar array contests:\n";
    for(int i =0;i<3;i++){
         cout<<"Brand: "<<arr[i].name<<endl;
         cout <<"Weight: "<<arr[i].weight<<endl;
         cout << "Calories: " << arr[i].calories<<endl;
    }

    delete[] arr;
    return 0;
}

