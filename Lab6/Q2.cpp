#include<iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volumn =0;
};

float calu_volumn(float a, float b, float c);

int main(){
    box ma;
    cout<<"Before setting volume:\n";
    cout<<"Maker: ";
    cin.getline(ma.maker,40);
    cout<<"Height: ";
    cin >> ma.height;
    cout<<"Width: ";
    cin >> ma.width;
    cout<<"Length: ";
    cin >> ma.length;
    cout<<"Volumn: ";
    cout<<ma.volumn<<endl;
    ma.volumn=calu_volumn(ma.height,ma.length,ma.width);
    cout<<"After setting volume:\n";
    cout<<"Maker: ";
    cout<<ma.maker<<endl;
    cout<<"Height: ";
    cout<< ma.height<<endl;
    cout<<"Width: ";
    cout<< ma.width<<endl;
    cout<<"Length: ";
    cout<< ma.length<<endl;
    cout<<"Volumn: ";
    cout<<ma.volumn<<endl;
    return 0;
    
}

float calu_volumn(float a, float b, float c){
    return a*b*c;
}