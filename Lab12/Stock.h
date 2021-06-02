#ifndef LAB12_STOCK_H
#define LAB12_STOCK_H

#include <cstring>
#include <iostream>

class Stock
{
private:
    char *company;
    int shares;
    double share_val;
    double total_val;

    void set_tot()
    { total_val = shares * share_val; }

public:
    Stock();

    Stock(const Stock & st);

    ~Stock();

    char *getCompany() const;

    int getShares() const;

    double getShareVal() const;

    double getTotalVal() const;

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    friend std::ostream &operator<<(std::ostream &os, const Stock &s);

    const Stock &topval(const Stock &s) const;

    Stock(const char *co, long n, double pr);
};

#endif //LAB12_STOCK_H
