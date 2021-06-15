#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int size, capacity;
    stack<int> s1, s2;

public:
    MyQueue(int x)
    {
        size = 0;
        capacity = x;
    }
    void push(int x);
    int pop();
    int getFront();
    bool isFull();
    bool isEmpty();
};

bool MyQueue::isEmpty()
{
    if (size == 0)
        return true;
    else
        return false;
}

bool MyQueue::isFull()
{
    if (size == capacity)
        return true;
    else
        return false;
}

void MyQueue::push(int x)
{
    if (isFull())
        return;

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    size++;
    return;
}

int MyQueue::pop()
{
    if (isEmpty())
        return -1;
    size--;

    int res = s1.top();
    s1.pop();
    return res;
}

int MyQueue::getFront()
{
    if (isEmpty())
        return -1;

    int res = s1.top();
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    MyQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(12);

    cout << "IsFull: " << q.isFull() << endl;

    cout << q.pop()
         << " dequeued from queue\n";
    cout << "Front item is "
         << q.getFront() << endl;
    cout << "IsEmpty: " << q.isEmpty() << endl;
    cout << "IsFull: " << q.isFull() << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout << "IsEmpty: " << q.isEmpty() << endl;

    q.push(122);

    cout << "Front item is "
         << q.getFront() << endl;

    return 0;
}