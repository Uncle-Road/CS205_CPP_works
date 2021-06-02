#include "golf.h"
#include <cstring>

void setgolf(golf& g,const char* name,int hc){
    cout<<"First version of setgolf function:\n";
    strcpy(g.fullname,name);
    g.handicap = hc;
}

int setgolf(golf& g){
    cout<<"Second version of setgolf function"<<endl;
    do{
        cout <<"Enter the fullname:";
        cin.getline(g.fullname, Len);
        cout<<"Enter the hanicap:";
        (cin >> g.handicap).get();
    }while(g.fullname[0]=='\0');
    return 0;
}

void handicap(golf& g,int hc){
    g.handicap = hc;
}

void showgolf(const golf &g){
    cout<<"The name of golf is "<<g.fullname<<" and its handicap is "<<g.handicap<<endl;
}

