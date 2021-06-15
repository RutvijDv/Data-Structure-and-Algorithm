#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int size, capacity;
    queue<int> q1, q2;

public:
    MyStack(int x)
    {
        size = 0;
        capacity = x;
    }
    void push(int x);
    int pop();
    int getTop();
    bool isFull();
    bool isEmpty();
};

bool MyStack::isEmpty()
{
    if (size == 0)
        return true;
    else
        return false;
}

bool MyStack::isFull()
{
    if (size == capacity)
        return true;
    else
        return false;
}

void MyStack::push(int x)
{
    if (isFull())
        return;

    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    size++;
    return;
}

int MyStack::pop()
{
    if (isEmpty())
        return -1;
    size--;

    int res = q1.front();
    q1.pop();
    return res;
}

int MyStack::getTop()
{
    if (isEmpty())
        return -1;

    int res = q1.front();
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    MyStack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(12);

    cout << "IsFull: " << s.isFull() << endl;

    cout << s.pop()
         << " popped from stack\n";
    cout << "Top item is "
         << s.getTop() << endl;
    cout << "IsEmpty: " << s.isEmpty() << endl;
    cout << "IsFull: " << s.isFull() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout << "IsEmpty: " << s.isEmpty() << endl;

    s.push(122);

    cout << "Top item is "
         << s.getTop() << endl;

    return 0;
}
