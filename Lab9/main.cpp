#include "sales.h"

int main() {
    SALES::Sales sales{} ;
    double arr[3];
    arr[0] = 345.2;
    arr[1] = 621.8;
    arr[2] = 1073.5;
    SALES::setSales(sales,arr,3);
    SALES::showSales(sales);
    SALES::Sales sales1{};
    SALES::setSales(sales1);
    SALES::showSales(sales1);
    return 0;
}


// #include "golf.h"

// int main(){
//     golf ann;
//     setgolf(ann,"Ann Birdfree",24);
//     showgolf(ann);
//     golf andy;
//     setgolf(andy);
//     showgolf(andy);
//     return 0;
// }
