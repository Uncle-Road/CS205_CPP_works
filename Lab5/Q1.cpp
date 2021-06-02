#include<iostream>
using namespace std;
int main(){
    int a;
    int sum =0;
   
    do{
    cout << "Enter an integer number: ";
    cin >> a;
    sum+=a;
    cout<< "The cumulative sum of the entries to date is: "<<sum<<endl;
    } while (a!=0);
    
    return 0;
}
