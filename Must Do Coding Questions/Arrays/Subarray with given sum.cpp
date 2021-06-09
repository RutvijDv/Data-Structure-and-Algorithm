#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int s)
{
    vector<int> res;
    int sum = 0, start_index = 0, end_index;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        end_index = i;
        while (sum >= s)
        {
            if (sum == s)
            {
                flag = false;
                break;
            }
            sum -= arr[start_index];
            start_index++;
        }
        if (!flag)
            break;
    }

    if (flag)
    {
        res.push_back(-1);
        return res;
    }
    res.push_back(start_index + 1);
    res.push_back(end_index + 1);

    return res;
}