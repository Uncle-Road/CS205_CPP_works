#include <iostream>
#include "Stock.h"
#include "Stack.h"

using namespace  std;

int main() {
    Stock a = Stock("suprme", 123, 23.5);
    cout <<"Initial"<< a;
    a.buy(10, 12.4);
    cout <<"after buy"<< a;
    Stock b = a;
    cout << b;
    a.sell(20, 29.4);
    cout<<"after sell"<<a;
    a.update(45);
    cout <<"after update"<< a;
    cout << b;

    long popped;
    Stack stack = Stack(10);
    stack.show();
    stack.push(1);
    stack.push(3);
    stack.show();
    stack.pop(reinterpret_cast<Item &>(popped));
    stack.show();

    cout<<"deep copy"<<endl;
    Stack st1 = Stack(7);
    st1.push(33);
    st1.push(5);
    stack = st1;
    Stack st2 = st1;
    stack.show();
    st2.show();
    return 0;
}
