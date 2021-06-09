#include <bits/stdc++.h>
using namespace std;

//Use empty string and start copying the characters adn replace where required

//simple method
void replaceSpaces(char a[], int n)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ' ')
            len += 3;
        else
            len++;
    }

    len--;
    for (int j = n - 1; j >= 0; j--)
    {
        if (a[j] == ' ')
        {
            a[len--] = '0';
            a[len--] = '2';
            a[len--] = '%';
        }
        else
        {
            a[len--] = a[j];
        }
    }
    cout << a << endl;
    return;
}

//use find and replace
void replaceSpaces(string a)
{
    int idx = a.find(" ");

    while (idx != string::npos)
    {
        a.replace(idx, 1, "%20");
        idx = a.find(" ");
    }
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char a[] = "Mr John Smith";
    replaceSpaces(a, 13);

    return 0;
}
