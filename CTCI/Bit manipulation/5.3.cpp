#include <bits/stdc++.h>
using namespace std;

//BruteForce

vector<int> getSequence(int n)
{
    vector<int> seq;
    int search = 0, count = 0;
    while (n != 0)
    {
        int z = n & 1;
        if ((n & 1) != search)
        {

            seq.push_back(count);
            if (search == 0)
                search = 1;
            else
                search = 0;
            count = 0;
        }
        count++;
        n = n >> 1;
    }
    seq.push_back(count);
    return seq;
}

int getLongest(vector<int> seq)
{
    int res = INT_MIN;
    for (int i = 0; i < seq.size(); i += 2)
    {
        int zerolen = seq[i];

        int leftonelen = i + 1 < seq.size() ? seq[i + 1] : 0;
        int rightonelen = i - 1 >= 0 ? seq[i - 1] : 0;

        if (zerolen == 0)
        {
            res = max(res, max(leftonelen, rightonelen));
        }
        else if (zerolen == 1)
        {
            res = max(res, rightonelen + leftonelen + 1);
        }
        else if (zerolen > 1)
        {
            res = 1 + max(res, max(leftonelen, rightonelen));
        }
    }

    return res;
}

int solver(int n)
{
    vector<int> sequence;
    sequence = getSequence(n);

    int res = getLongest(sequence);

    return res;
}

//Efficient
int solve(int n)
{
    int x = n, res = INT_MIN, prev = 0, curr = 1, count = 0;

    while (x != 0)
    {
        if (x & 1 == 1)
        {
            count++;
        }
        else
        {
            count = curr - prev;
            prev = curr;
        }
        res = max(res, count);
        curr++;
        x = x >> 1;
    }

    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 1775;

    int res = solver(n);
    cout << res << endl;

    return 0;
}