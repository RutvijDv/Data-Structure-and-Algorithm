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
    int min = -1;
    int dummyVal = 9999;

public:
    void push(int x);
    int pop();
    int getMin();
};

void SpecialStack::push(int x)
{
    if (empty() || x < min)
    {
        min = x;
    }
    Stack::push(x * dummyVal + min);

    return;
}

int SpecialStack::pop()
{
    int res = -1;
    if (!Stack::empty())
    {
        res = Stack::pop();
        res = res / dummyVal;
    }
    return res;
}

int SpecialStack::getMin()
{
    int res = -1;
    if (!Stack::empty())
    {
        res = Stack::getTop();
        res = res % dummyVal;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    SpecialStack s;

    vector<int> arr = {3, 2, 6, 1, 8, 5};

    for (int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
        cout << "pushed: " << arr[i] << endl;
        cout << "min is: " << s.getMin() << endl;
    }

    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "popped: " << s.pop() << endl;
        cout << "min is: " << s.getMin() << endl;
    }
    return 0;
}