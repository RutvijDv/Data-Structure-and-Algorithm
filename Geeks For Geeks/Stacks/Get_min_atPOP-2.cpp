#include <bits/stdc++.h>
using namespace std;

//Using 2 stacks one for data and other for minimum element till that point
//Space optimised ---> Store only min elements once in min stack

class Stack
{
private:
    static const int max = 1000;
    int arr[max];
    int top;

public:
    Stack()
    {
        top = -1;
    };
    void push(int x);
    int pop();
    int getTop();
    bool empty();
};

void Stack::push(int x)
{
    if (top + 1 < max)
    {
        top++;
        arr[top] = x;
    }
    return;
}

int Stack::pop()
{
    int res = -1;
    if (top >= 0)
    {
        res = arr[top];
        top--;
    }
    return res;
}

bool Stack::empty()
{
    if (top == -1)
        return true;
    else
        return false;
}

int Stack::getTop()
{
    int res = -1;
    if (top >= 0)
    {
        res = arr[top];
    }
    return res;
}

class SpecialStack : public Stack
{
    Stack min;

public:
    void push(int x);
    int pop();
    int getMin();
};

void SpecialStack::push(int x)
{
    if (empty())
    {
        Stack::push(x);
        min.push(x);
    }
    else
    {
        int y = min.getTop();
        if (x <= y)
        {
            min.push(x);
        }
        Stack::push(x);
    }
    return;
}

int SpecialStack::pop()
{
    int res = -1;
    if (!Stack::empty())
    {
        res = Stack::pop();
        if (res == min.getTop())
        {
            min.pop();
        }
    }
    return res;
}

int SpecialStack::getMin()
{
    int res = -1;
    if (!Stack::empty())
    {
        res = min.getTop();
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin();
    return 0;
    return 0;
}