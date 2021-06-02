#include <iostream>
#include "Number.h"

using namespace std;

Number::Number() : num(0) {}

Number::Number(int n) : num(n) {}

Number Number::operator++() {
        num++;
        return *this;

}

Number Number::operator--() {
        num--;
        return *this;
}


Number Number::operator++(int) {
        Number copy = *this;
        ++(*this);
        return copy;
}

Number Number::operator--(int) {
        Number copy = *this;
        --(*this);
        return copy;
}

std::ostream &operator<<(std::ostream &out, const Number &n) {
        out << n.num;
        return out;
}
