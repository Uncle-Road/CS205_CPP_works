#include <iostream>
using namespace std;

class Number {
private:
    int num;
    
public:
    Number();

    Number(int n);

    Number operator++() ;
    
    Number operator--() ;

    Number operator++(int);

    Number operator--(int);

    friend std::ostream &operator<<(std::ostream &out, const Number &n) ;
};