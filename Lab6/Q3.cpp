#include<iostream>

using namespace std;

int Fill_array(double arr[], int size);
void Show_array(double *arr, int size);
void Reverse_array(double *arr, int size);

int main(){
    int size; 
    cout<<"Enter the size of an array:";
    cin>>size;
    double arr[size];
    Fill_array(arr ,size);
    Show_array(arr,size);
    Reverse_array(arr,size);
    return 0;
}

int Fill_array(double arr[], int size){
    for(int i =0;i<size;i++){
        cout<< "Enter value #"<<i+1<<": ";
        cin>>arr[i];
    }
    return 0;
}
void Show_array(double *arr, int size){
    for(int i =0;i<size;i++){
        cout << arr[i] <<" ";
    }
    cout<<endl;
    for(int i =size-1;i>=0;i--){
        cout << arr[i] <<" ";
    }
    cout <<endl;

}
void Reverse_array(double *arr, int size){
    cout << arr[size -1] <<" ";
    for(int i =1 ; i<size-1;i++){
        cout << arr[i] <<" ";
    }
    cout<<arr[0]<<endl;
}