#include<iostream>
#include<cstring>

using namespace std;

int main(){
    string a ;
    int count =0;
do{
    cin>> a;
    count++;
}while(a.compare("done"));

    cout<< "You enter a total of " <<count-1 <<" word！"<<endl;

    return 0;
}