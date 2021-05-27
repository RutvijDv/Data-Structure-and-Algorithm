
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    static bool comparison(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        int res = 0, count = 0;

        sort(arr, arr + n, comparison);

        int result[n];
        bool slot[n];
        for (int i = 0; i < n; i++)
            slot[i] = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
            {
                if (slot[j] == false)
                {
                    res += arr[i].profit;
                    count++;
                    slot[j] = true;
                    break;
                }
            }
        }

        vector<int> ans(2);
        ans[0] = count;
        ans[1] = res;
        return ans;
    }
};