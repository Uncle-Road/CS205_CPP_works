#include<iostream>
#include<cmath>
#include<string>
#include<regex>

using namespace std;

const double R = 6371;
const double PI = 3.1415926535;
const double val = PI/180;

struct city{
    string name;
    double latitude;
    double longitude;
};


double findDistance(city city1, city city2);
string remove_space(string name);
int judge_city_index(double latitude,double longitude);
int judge_city_name(string name);
int judge_index_format(string a,string b);
bool check_double_char(string & str);
int some_special_case(double a, double b);


int main(){
    //difine the city
    city c1 ;
    city c2 ;
    //input the data
    cout<<"please input the first city name(without special characters):";
    char char1;
    while((char1=cin.get())!='\n')
    c1.name=c1.name+char1;
    c1.name =remove_space(c1.name);
    if(judge_city_name(c1.name)){
        return -1;
    }
    cout<<"please input the latitude and longitude:";
    string lat1;
    string lon1;
    cin >> lat1;
    cin >> lon1;
    if(judge_index_format(lat1,lon1)){
        return -1;
    }
    c1.latitude = stod(lat1);
    c1.longitude = stod(lon1);
    
    if(judge_city_index(c1.latitude,c1.longitude)){
       return -1;
    }

    if(some_special_case(c1.latitude,c1.longitude)){
        return -1;
    }
    cin.get();

    cout<<"please input the second city name(without special characters):";
    char char2;
    while((char2=cin.get())!='\n')
    c2.name=c2.name+char2;
    c2.name =remove_space(c2.name);
    if(judge_city_name(c2.name)){
        return -1;
    }

   cout<<"please input the latitude and longitude:";
    string lat2;
    string lon2;
    cin >> lat2;
    cin >> lon2;
   
    if(judge_index_format(lat2,lon2)){
        return -1;
    }

    c2.latitude = stod(lat2);
    c2.longitude = stod(lon2);
    cin.get();

    if(judge_city_index(c2.latitude,c2.longitude)){
       return -1;
    }

    if(some_special_case(c2.latitude,c2.longitude)){
        return -1;
    }
    

    //calu the distance
    double distance = findDistance(c1,c2);
    //out 
    cout<<endl;
    cout << "The first city:"<<c1.name<<endl;
    cout << "The latitude and longitude of first city:";  
    cout<< c1.latitude;
    cout<<" " ;
    cout<< c1.longitude<<endl;

    cout << "The second city:"<<c2.name<<endl;
    cout << "The latitude and longitude of second city:";
    cout<< c2.latitude;
    cout<<" ";
    cout<< c2.longitude<<endl;
    
    cout<< "The distance is: "<< distance <<" km"<<endl;
    return 0;
}

double findDistance(city city1, city city2){
    double ans =0;
    double phi1 = 90 - city1.latitude;
    double theta1 = city1.longitude;
    double phi2 = 90 - city2.latitude;
    double theta2 = city2.longitude;
    double c = sin(phi1*val)*sin(phi2*val)*cos((theta1-theta2)*val)+cos(phi1*val)*cos(phi2*val);
    ans = R * acos(c);
    return ans;
}
string remove_space(string name){
    if(name.empty()){
        return name;
    }else{
        name.erase(0,name.find_first_not_of(" "));
        name.erase(name.find_last_not_of(" ")+1);
        return name;
    }
}
int judge_city_index(double latitude,double longitude){
    if(!(latitude<=90&&latitude>=-90)||!(longitude<=180&&longitude>=-180)){
        cout<<"latitude should be [-90,+90]"<<endl;
        cout<< "longitude should be [-180,+180]"<<endl;
        return -1;
    }
    return 0;
}
int judge_city_name(string name){
    for(auto i:name){
        if(!(' '==i ||','==i ||(i>='A' &&i<= 'Z')||(i>='a' &&i<='z'))){
            cout << "City's name should not contains special characters" <<endl;
            return -1;
        }
    }
    return 0;
}
int judge_index_format(string a,string b){
    for(auto i:a){
        if(!('.'==i ||(i>='0' &&i<= '9') || i == '+' || i=='-')){
            cout<<"Invalid format, not contains special chararcters."<<endl;
           return -1;
        }
    }
     for(auto i:b){
        if(!('.'==i ||(i>='0' &&i<= '9') || i == '+' || i=='-')){
             cout<<"Invalid format, not contains special chararcters."<<endl;
            return -1;
        }
    }
    if(!check_double_char(a)||!check_double_char(b)){
        return -1;
    }

    try {
        stof(a);
        stof(b);
    } catch(std::invalid_argument e) {
        cout << "input should follow correct double format" << endl;
        return -1;
    }

    return 0;
}
bool check_double_char(string & str) {
    if (count(str.begin(), str.end(), '.') > 1 || (count(str.begin(), str.end(), '+') + count(str.begin(), str.end(), '-') > 1)) {
        cout<< "Invallid, too many '.' '+' '-'."<<endl;
        return false;
    }
    return true;
}
int some_special_case(double a, double b){
    if(a==0.0&&b==0.0){
        cout<<"This index not exist a city."<<endl;
        return -1;
    }
    return 0;
}
