#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>


using namespace std;

int main(){
    char input[100];
    string readline;
    char input2[100];
    cout<< "Please input a string:" ;
    cin.getline(input,100);
    
    fstream finout1("f1.txt",ios::in|ios::out);
    fstream finout2("f2.txt",ios::in|ios::out);


    if(finout1.good()&&finout2.good()){
        finout1 << input <<endl;
        finout1.clear();
        finout1.seekg(0);

        for(int i =0;i<100;i++){
            input2[i] = toupper(input[i]);
        }
        
        finout2 << input2<<endl;
        finout2.clear();
        finout2.seekg(0);


        cout <<endl <<endl;
        cout<<"The contends of f1.txt :";
        while(!finout1.eof()){
        getline(finout1,readline);
        cout<<readline<<endl;
        }
        finout1.close();

        cout<<"The contends of f2.txt :";
        while(!finout2.eof()){
            getline(finout2,readline);
            cout<<readline<<endl;
        }
        finout2.close();

    }else{
        cout << "txt could not be opend."<<endl;
    }

    return 0;

    //Hi! I am Candy, 18 years old.
}