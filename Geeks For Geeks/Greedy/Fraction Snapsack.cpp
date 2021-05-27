
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    static bool mycomp(Item a, Item b)
    {
        double rateA = (double)a.value / a.weight;
        double rateB = (double)b.value / b.weight;

        return rateA > rateB;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, mycomp);
        double res = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight < W)
            {
                res += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                double x = (double)arr[i].value / arr[i].weight;
                res += x * (W);
                return res;
            }
        }

        return res;
    }
};