#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib> //support for exit()
#include <algorithm>
#include <vector>

using namespace std;

struct city
{
    string name ;
    string country;
    double longitude;
    double latitude;
};

const double R = 6371;
const double PI = 3.1415926535;
const double val = PI/180;

#define MAX_NAME_LENGTH 35
#define MAX_ARRAY_LENTH 1000
#define FILE_NAME "world_cities.csv"

vector<const city *> choose_City{};

bool end_judge(string str);
string trim(string str);
bool is_number(const std::string &s);
vector<city> readFile(const string &filename);
bool InputCity(const city **p, const vector<city> &cityList);
double findDistance(const city &city1, const city &city2);
void process(vector<city> cityList);

int main(){
    vector<city> cityList = readFile(FILE_NAME);
    if(cityList.size()==0){
       return 0;
    }
    process(cityList);
    cout<<"Progarm is end!"<<endl;
    return 0;
}
void process(vector<city> cityList){
     while (true) {
        const city *c1 = nullptr, *c2 = nullptr;
        while (c1 == nullptr) {
            cout<<"\n------------------------------------"<<endl;
            cout<<"Input \"bye\" to end the programmer! You need at least input three char"<<endl;
            cout << "please input the first city name: ";
            if (!InputCity(&c1, cityList)) {
                return ;
            }
        }
        while (c2 == nullptr) {
            cout << "please input the second city name: ";
            if (!InputCity(&c2, cityList)) {
                return ;
            }
        }
        double distance = findDistance(*c1, *c2);
        cout << "The distance between " << c1->name << " and " << c2->name << " is " << distance << " km." << endl;
    }
    return;
}
bool end_judge(string str) {
    if (str.size() == 3 
        && ('b' == str[0] || 'B' == str[0]) 
        && ('y' == str[1] || 'Y' == str[1]) 
        && ('e' == str[2] || 'E' == str[2])
        ) {
        return true;
    }
    return false;
}
string trim(string str) {
    if (str.empty()) return str;
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}
bool is_number(const string &str) {
    bool a,b;
    a= !str.empty();
    b= find_if(str.begin(), str.end(),[](unsigned char c) { return !isdigit(c); }) == str.end();
    return a&&b;
}
vector<city> readFile(const string &filename){
    vector<city> cityList;
    ifstream inFile;
    inFile.open(filename);
    if(!inFile.good()){
        cout << "we can\'t open this file: " <<filename <<endl;
        exit(EXIT_FAILURE);
        return cityList;
    }

    int line_serial =1;
    string data;
    while(getline(inFile,data)){
        if(cityList.size() >= MAX_ARRAY_LENTH){
            cout <<"This file too larger! It more than " << MAX_ARRAY_LENTH <<" lines, operate skipping instruction." <<endl;
        }
        string separate = ",";
        string information[5];
        int num =0;
        size_t index=0;
        //divide
        while((index = data.find(separate)) != string::npos){
            information[num] = data.substr(0,index);
            data.erase(0,index + 1);
            num++;
        }
        information[num] = data;
        if(information[0].size() > MAX_NAME_LENGTH || information[2].size()>MAX_NAME_LENGTH ){
            cout <<"No." <<line_serial<<" name length is larger than "<<MAX_NAME_LENGTH << " skip this line."<<endl;
        }
        //store 
        transform(information[0].begin(),information[0].end(),information[0].begin(),::toupper);
        city city1;
        city1.name = information[0];
        city1.country = information[2];
        city1.latitude = stod(information[3]);
        city1.longitude = stod(information[4]);

        cityList.push_back(city1);
        line_serial++;
    }
    return cityList;

}
bool InputCity(const city **pt, const vector<city> &cityList) { 
    string str;
    getline(cin, str);
    str = trim(str);
     if(end_judge(str)){
        return false;
    }
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    if (is_number(str) && !cityList.empty()) {
        int num = stoi(str);
        if (num < 0 || num >= choose_City.size()) {
            cout << "please enter a correct input" << endl;
            return true;
        }
        *pt = choose_City[num];
        choose_City.clear();
        return true;
    }

    if (str.size() < 3) {
        cout << "Too short, the City name at least 3 char." << endl;
        return true;
    }

    choose_City.clear();
    for (auto city = cityList.begin(); city != cityList.end(); city++) {
        if (city->name.rfind(str, 0) == 0) {
            if (choose_City.size() == 1) {
                cout << "Those city is match, input integer to choose city" << endl;
                cout << "0. " << choose_City[0]->name << ", " << choose_City[0]->country << endl;
                cout << "1. " << city->name << ", " << city->country << endl;
            } else if (choose_City.size() > 1) {
                cout << choose_City.size() << ". " << city->name << ", " << city->country << endl;
            }
            choose_City.push_back(&*city);

        }
    }

    if (choose_City.size() >= 2) {
        return true;
    }else if (choose_City.size() == 0){
        cout<<"NO CITY EXIST!"<<endl;
        return true;
    }
    *pt = choose_City[0];
    return true;
}
double findDistance(const city &city1, const city &city2){
    double ans =0;
    double phi1 = 90 - city1.latitude;
    double theta1 = city1.longitude;
    double phi2 = 90 - city2.latitude;
    double theta2 = city2.longitude;
    double c = sin(phi1*val)*sin(phi2*val)*cos((theta1-theta2)*val)+cos(phi1*val)*cos(phi2*val);
    ans = R * acos(c);
    return ans;
}
