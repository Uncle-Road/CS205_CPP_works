#ifndef CS205_CPP_LAB11_EXERCISE_COMPLEX_H
#define CS205_CPP_LAB11_EXERCISE_COMPLEX_H

#include<iostream>
#include<string>
using namespace std;

class Complex {
private:
    double imag;
    double real;

public:
    Complex();

    Complex(double re, double im);

    Complex(double re);

    void Show() const;

    Complex operator+(const Complex &other) const;

    Complex operator+(double r) const;

    Complex operator-(const Complex &other) const;

    Complex operator~() const;

    Complex operator*(const Complex &other) const;

    bool operator==(const Complex &other) const;

    bool operator!=(const Complex &other) const;

    friend Complex operator+(double r, const Complex &other);

    friend Complex operator*(double r, const Complex &other);

    friend std::ostream &operator<<(std::ostream &os, const Complex &other);

    friend std::istream &operator>>(std::istream &is, Complex &other);

};

#endif