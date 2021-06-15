#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class MyQueue
{
private:
    Node *front;
    Node *rear;
    int size, capacity;

public:
    MyQueue(int x)
    {
        front = NULL;
        rear = NULL;
        size = 0;
        capacity = x;
    }
    void push(int x);
    int pop();
    int getRear();
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

    if (isEmpty())
    {
        rear = new Node(x);
        front = rear;
    }
    else
    {
        rear->next = new Node(x);
        rear = rear->next;
    }

    size++;

    return;
}

int MyQueue::pop()
{
    if (isEmpty())
        return -1;
    size--;

    int res = front->data;

    Node *temp = front;
    front = front->next;
    delete (temp);

    return res;
}

int MyQueue::getFront()
{
    if (isEmpty())
        return -1;

    int res = front->data;

    return res;
}

int MyQueue::getRear()
{
    if (isEmpty())
        return -1;

    int res = rear->data;

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
    cout << "Rear item is "
         << q.getRear() << endl;
    cout << "IsEmpty: " << q.isEmpty() << endl;
    cout << "IsFull: " << q.isFull() << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout << "IsEmpty: " << q.isEmpty() << endl;

    q.push(12);

    cout << "Front item is "
         << q.getFront() << endl;
    cout << "Rear item is "
         << q.getRear() << endl;

    return 0;
}
