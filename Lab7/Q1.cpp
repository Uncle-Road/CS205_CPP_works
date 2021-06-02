#include <iostream>
#include <cstring>

using namespace std;

struct stringy
{
    char *str;
    int ct;
};

void set(stringy &stry, char *str);
void show(const stringy &stry, int times = 1);
void show(const char *str, int times = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it uesd to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done");

    return 0;
}

void set(stringy &stry, char *str)
{
    int len = strlen(str);
    char *copy = new char[len];
    strcpy(copy, str);
    stry.ct = len;
    stry.str = copy;
}

void show(const stringy &stry, int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << stry.str << endl;
    }
}

void show(const char *str, int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << str << endl;
    }
}
