#include <iostream>
using namespace std;
int main(){
    cout<<"Enter the number of secinds:";
    int a;
    cin >> a;
    int days = a/86400;
    int hours = a%86400/3600;
    int minutes =a%3600/60;
    int seconds =a%60;
    cout<< a<<" seconds = " <<days<<" days "<<hours<<" hours "
    <<minutes<<" minutes "<< seconds <<" seconds "<<endl;
    return 0;
}