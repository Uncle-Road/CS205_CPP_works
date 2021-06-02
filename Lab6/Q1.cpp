#include<iostream>

using namespace std;

int mul_t(int a, int b);
int add_i(int a ,int b);
int red_u(int a, int b);
int di_v(int a ,int b);
int mod_u(int a, int b);

int main(){
    char c ='y';
    int choise;
    int a, b;
    cout<<"--------------------------------"<<endl<<"                MENU"<<endl<<"--------------------------------"<<endl;
    cout<<"1.Add\n2.Subsract\n3.Multiply\n4.Divide\n5.Modulus\n";
    do{
    cout<<"Enter your choise(1~5):";
    cin>>choise;
    cout<<"Enter your integer number:";
    cin>>a>>b;
    cout<<endl;
    if(choise==1){
        cout<<"Result: "<<add_i(a,b)<<endl;
    }else if(choise == 2){
        cout<<"Result: "<<red_u(a,b)<<endl;
    }else if(choise ==3){
        cout<<"Result: "<<mul_t(a,b)<<endl;
    }else if(choise ==4){
        cout<<"Result: "<<di_v(a,b)<<endl;
    }else if(choise ==5){
        cout<<"Result: "<<mod_u(a,b)<<endl;
    }
    cout<<"Press y or Y to continue:";
    cin>>c;


    }while (c=='y'||c=='Y');
    
    return 0;
}

int mul_t(int a, int b){
    return a*b;
}
int add_i(int a ,int b){
    return a+b;
}
int red_u(int a, int b){
    return a-b;
}
int di_v(int a, int b){
    return a/b;
}
int mod_u(int a, int b){
    return a%b;
}
