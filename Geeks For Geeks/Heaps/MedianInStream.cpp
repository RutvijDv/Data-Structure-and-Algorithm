#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
    int n = 0;

public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (pqMax.size() == pqMin.size())
            pqMax.push(x);
        else
            pqMin.push(x);

        n++;
        if (n > 1)
            balanceHeaps();
    }

    //Function to balance heaps.
    void balanceHeaps()
    {
        int x = pqMax.top();
        int y = pqMin.top();

        if (x > y)
        {
            pqMax.pop();
            pqMin.pop();

            pqMax.push(y);
            pqMin.push(x);
        }

        return;
    }

    //Function to return Median.
    double getMedian()
    {
        if (n > 0)
        {
            if (pqMax.size() == pqMin.size())
                return (pqMin.top() + pqMax.top()) / 2;
            else
                return pqMax.top();
        }
        return 1.0;
    }
};