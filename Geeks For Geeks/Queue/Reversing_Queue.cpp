#include <bits/stdc++.h>
using namespace std;

//Simply using Stack

//Using Recursion
void reverse(queue<int> &q)
{
    if (q.empty())
        return;

    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);

    return;
}

void show(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    queue<int> q;

    for (int i = 0; i < 10; i++)
        q.push(i);

    cout << "Initially ";
    show(q);
    cout << endl;

    reverse(q);

    cout << "Finnaly ";
    show(q);
    cout << endl;
}