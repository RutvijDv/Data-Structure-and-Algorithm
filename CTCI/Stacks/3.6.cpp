#include <bits/stdc++.h>
using namespace std;

class Animals
{
private:
    queue<int> dogs;
    queue<int> cats;

public:
    void push(char c, int x);
    int popAny();
    int popCat();
};

void Animals::push(char c, int x)
{
    if (c == 'd')
        dogs.push(x);
    else
        cats.push(x);
}

int Animals::popAny()
{
    int a = dogs.front();
    int b = cats.front();

    if (a < b)
    {
        dogs.pop();
        return a;
    }
    else
    {
        cats.pop();
        return b;
    }
}

int Animals::popCat()
{
    int a = cats.front();
    cats.pop();
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Animals shelter;
    int n = 10, i = 1;

    while (n--)
    {
        char x;
        cin >> x;

        shelter.push(x, i);
        i++;
    }

    cout << "PopAny " << shelter.popAny() << endl;
    cout << "PopAny " << shelter.popAny() << endl;

    cout << "PopCat " << shelter.popCat() << endl;
    cout << "PopCat " << shelter.popCat() << endl;
}
