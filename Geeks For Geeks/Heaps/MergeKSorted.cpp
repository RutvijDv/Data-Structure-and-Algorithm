#include <bits/stdc++.h>
using namespace std;

//put all elements in one array and sort them -> Super Naive

//Merge alla arrays one-by-one

//Use Min Heap
struct myTriplet
{
    int element;
    int i;
    int j;

    myTriplet(int a, int b, int c)
    {
        element = a;
        i = b;
        j = c;
    }
};

struct cmp
{
    bool operator()(myTriplet a, myTriplet b)
    {

        return a.element > b.element;
    }
};

class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;

        priority_queue<myTriplet, vector<myTriplet>, cmp> pq;

        for (int i = 0; i < K; i++)
        {
            myTriplet x(arr[i][0], i, 1);
            pq.push(x);
        }

        while (!pq.empty())
        {

            myTriplet x = pq.top();

            res.push_back(x.element);
            pq.pop();

            if (x.j < K)
            {
                myTriplet y(arr[x.i][x.j], x.i, x.j + 1);
                pq.push(y);
            }
        }

        return res;
    }
};