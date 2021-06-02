#include<iostream>
#include<cstring>

using namespace std;

int main(){
    char str[20];
    cout<<"What is your first name? ";
    cin.getline(str,20);
    cout << "What is your last name? ";
    string last; cin>>last;
    cout << "What letter grade do you deserve? ";
    string de;cin>>de;
    cout << "What is your age? ";
    int age;cin>>age;

    cout << "The information you entered is:\n";
    cout<<"Name:"<<str<<", "<<last<<endl;
    cout<<"Grade: "<<de<<endl;
    cout<<"Age: "<<age<<endl;
    return 0;
}
