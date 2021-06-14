#include <bits/stdc++.h>
using namespace std;

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

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Stack s;

    s.push(1);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl;
    s.push(5);
    cout << s.pop();

    return 0;
}