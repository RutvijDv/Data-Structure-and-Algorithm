#include <bits/stdc++.h>
using namespace std;

//O(n^2) solution ---> Naive Approach

vector<int> calculateSpan(int price[], int n)
{
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++)
    {
        int curr = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (price[j] <= price[i])
                curr++;
            else
                break;
        }

        res[i] = curr;
    }

    return res;
}

//Better Solution ---> O(n) time O(n) space

vector<int> calculateSpan(int price[], int n)
{
    vector<int> res(n, 0);

    stack<int> st;
    st.push(0);
    res[0] = 1;

    for (int i = 1; i < n; i++)
    {

        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    return res;
}