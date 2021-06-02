#include "sales.h"
#include<iostream>
// using namespace std;
void SALES::setSales(SALES::Sales& s,const double  ar[],int n)
{
    std::cout<<"Non-interactive version of setSales() to provide values:"<<std::endl;
    s.max = ar[0];
    s.min = ar[0];
    for (int i = 0; i < std::min(n,4); ++i) {
        s.sales[i] =  ar[i];
        s.average+=ar[i];
        if (s.max<ar[i]){
            s.max = ar[i];
        }
        if (s.min>ar[i]){
            s.min = ar[i];
        }
    }
    s.average/=std::min(n,4);
}

void SALES::setSales(SALES::Sales &s)
{
    std::cout<<"Interactive version of setSales() to provide values:"<<std::endl;
    double num[4];
    std::cout<<"Enter sales for 4 quarters: "<<std::endl;
    std::cin>>num[0]>>num[1]>>num[2]>>num[3];
    s.max = num[0];
    s.min = num[0];
    for (int i = 0; i < 4; ++i) {
        s.sales[i] =  num[i];
        s.average+=num[i];
        if (s.max<num[i]){
            s.max = num[i];
        }
        if (s.min>num[i]){
            s.min = num[i];
        }
    }
    s.average/=4;
}

void SALES::showSales(const SALES::Sales& s)
{
    std::cout<<"Sales:"<<s.sales[0]<<" "<<s.sales[1]<<" "<<s.sales[2]<<" "<<s.sales[3]<<" "<<std::endl;
    std::cout<<"Average:"<<s.average <<std::endl;
    std::cout<<"Max:"<<s.max <<std::endl;
    std::cout<<"Min:"<<s.min <<std::endl;
}