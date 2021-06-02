#include<iostream>
#include<cmath>
using namespace std;

struct Candybar{
    char name[20];
    float weight;
    int calories; 
};

void print(Candybar bar);

int main(){
    int ans=0;
    float list[3];
    Candybar arr[3];
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
        list[i] =(float) arr[i].calories/arr[i].weight;
    }

    for(int i =1;i<3;i++){
        if(list[ans]<list[i]){
            ans = i;
        }
    }

    
    cout << endl <<endl;
    cout << "Displaying the CamdyBar array contests:\n";
    for(int i =0;i<3;i++){
        print(arr[i]);
    }
    cout<<endl<<endl;
    cout<<"The greatest calories per weight is: \n";
    cout << "Brand: "<<arr[ans].name<<endl;
    cout << "Caloriesper weight is:"<<list[ans]<<endl;
}

void print(Candybar bar){
    cout<<"Brand: "<<bar.name<<endl;
    cout <<"Weight: "<<bar.weight<<endl;
    cout << "Calories: " << bar.calories<<endl;
}