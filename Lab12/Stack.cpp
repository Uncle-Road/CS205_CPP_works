#include "Stack.h"

Stack::Stack(int n)
{
    size = n;
    top = 0;
    items = new Item[n];
}

Stack::Stack(const Stack &st)
{
    size = st.size;
    top = st.top;
    items = new Item[size];
    for (int i = 0; i < size; ++i)
    {
        items[i] = st.items[i];
    }
}

Stack::~Stack()
{
    delete[] items;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    } else
        return false;
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    } else
        return false;
}

Stack &Stack::operator=(const Stack &st)
{
    size = st.size;
    top = st.top;
    items = new Item[size];
    for (int i = 0; i < size; ++i)
    {
        items[i] = st.items[i];
    }
}

void Stack::show()
{
    for (int i = 0; i < top; i++)
    {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}
