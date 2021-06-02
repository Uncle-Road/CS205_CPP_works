#ifndef CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H
#define CS205_C_CPP_LAB11_EXERCISE_CANDYBAR_H

#include <iostream>

class CandyBar {
private:
    std::string name;
    double weight;
    int calories;
public:

    explicit CandyBar();

    explicit CandyBar(const char *n, double w, int32_t cal);

    explicit CandyBar(const std::string &n, double w, int32_t cal);

    // 拷贝构造函数 Copy Constructor
    CandyBar(const CandyBar &s);

    // 移动构造函数
    CandyBar(CandyBar &&s);

    // 拷贝赋值运算符 Copy Assignment operator
    CandyBar &operator=(const CandyBar &) = delete;

    // 移动赋值运算符 Move Assignment operator
    CandyBar &operator=(CandyBar &&data);

    int32_t setCandyBar();

    void showCandyBar();

};

CandyBar get_a_candyBar();

#endif