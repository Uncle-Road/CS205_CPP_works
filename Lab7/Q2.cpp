#include<iostream>

using namespace std;

template<typename T>
T max5(T x,T y, T z ,T w ,T v){
    T ans;
    ans = max(max(max(max(x,y),z),w),v);
    return ans;
    
}

int main(){
    cout << "Max int = "<<max5<int>(1,2,3,4,5)<<endl;
    cout << "Max double = " << max5<double>(1.1,2.0,3.0,4.0,5.5)<<endl;
    return 0;
}
