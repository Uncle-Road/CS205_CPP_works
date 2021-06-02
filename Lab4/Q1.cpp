#include<iostream>

using namespace std;

struct pizza{
char company[20];
int diameter;
float weight; 
};

int main(){
    pizza pi ;
    cout<<"Enter the name of pizza company: ";
    cin.getline(pi.company,20);
    cout<<"Enter the diameter of pizza (inchers): ";
    cin>>pi.diameter;
    cout<<"Enter the weight of the pizza （g):";
    cin>>pi.weight;
    cout<<"Displaying the information of the pizza"<<endl;
    cout<<"Company name: " << pi.company<<endl;
    cout<<"Pizza diameter: " << pi.diameter<<" inches"<<endl;
    cout<<"Pizza weight: "<<pi.weight <<" g"<<endl;
    return 0;

}
