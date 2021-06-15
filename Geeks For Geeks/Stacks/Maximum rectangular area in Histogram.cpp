#include <bits/stdc++.h>
using namespace std;

//Naive Approach O(n^2)

long long getMaxArea(long long arr[], int n)
{
    long long res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        long long curr = 1;

        //left
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
                curr++;
            else
                break;
        }

        //right
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
                curr++;
            else
                break;
        }

        res = max(res, curr * arr[i]);
    }

    return res;
}

//Better Solution O(n) space and O(n) time

vector<int> prevSmall(long long arr[], int n)
{

    vector<int> res(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return res;
}

vector<int> nextSmall(long long arr[], int n)
{

    vector<int> res(n, 0);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return res;
}

long long getMaxArea(long long arr[], int n)
{
    long long res = INT_MIN;

    vector<int> prevSmaller(n, 0);
    vector<int> nextSmaller(n, 0);

    prevSmaller = prevSmall(arr, n);
    nextSmaller = nextSmall(arr, n);

    for (int i = 0; i < n; i++)
    {
        long long curr = nextSmaller[i] - prevSmaller[i] - 1;
        res = max(res, curr * arr[i]);
    }

    return res;
}

//Best Solution O(1) space and O(n) time

long long getMaxArea(long long arr[], int n)
{
    long long res = INT_MIN;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            int idx = st.top();
            st.pop();
            long long curr = st.empty() ? i : i - st.top() - 1;
            res = max(res, curr * arr[idx]);
        }

        st.push(i);
    }

    while (!st.empty())
    {
        int idx = st.top();
        st.pop();
        long long curr = st.empty() ? n : n - st.top() - 1;
        res = max(res, curr * arr[idx]);
    }

    return res;
}