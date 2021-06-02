#include "Stock.h"

Stock::Stock()
{

}

Stock::Stock(const char *co, long n, double pr)
{
    int len = strlen(co);
    company = new char[len + 1];
    strcpy(company, co);
    shares = n;
    share_val = pr;
    set_tot();
}

Stock::Stock(const Stock &st)
{
    int len = strlen(st.getCompany());
    company = new char[len + 1];
    strcpy(company, st.getCompany());
    shares = st.getShares();
    share_val = st.getShareVal();
    set_tot();
}

Stock::~Stock()
{
    delete[] company;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    } else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    } else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    } else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream &operator<<(std::ostream &os, const Stock &s)
{
    os << "Company: " << s.getCompany()
       << " Shares: " << s.getShares() << "\n"
       << " Share Price: $" << s.getShareVal()
       << " Total Worth: $" << s.getTotalVal() << '\n';

    return os;
}

const Stock &Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

char *Stock::getCompany() const
{
    return company;
}

int Stock::getShares() const
{
    return shares;
}

double Stock::getShareVal() const
{
    return share_val;
}

double Stock::getTotalVal() const
{
    return total_val;
}
