#include<iostream>

using namespace std;

int main(){
    int arr[5];
    int* pt;
    cout<<"Enter 5 integers:\n";
    for(int i =0; i<5;i++){
        cin>>arr[i];
    }
    pt = arr;
    cout<<"The elements of thaarray in reverse orde are:"<<endl;
    for(int i =4;i>=0;i--){
        cout << *(pt+i)<< " ";
    }
    cout<<endl;
    return 0;
}