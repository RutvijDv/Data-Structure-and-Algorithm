#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

void MyQueue::push(int x)
{
    if (rear == NULL || front == NULL)
    {
        rear = new QueueNode(x);
        front = rear;
        return;
    }

    rear->next = new QueueNode(x);
    rear = rear->next;
    return;
}

int MyQueue ::pop()
{
    if (front == NULL)
        return -1;

    int x = front->data;
    front = front->next;
    return x;
}
