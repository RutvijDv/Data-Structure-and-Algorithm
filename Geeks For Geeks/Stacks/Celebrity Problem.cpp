#include <bits/stdc++.h>
using namespace std;

//Approach - 1 ---> Using outdegree and indegree concept of graph O(n^2) time and O(n) spaces

//Approach - 2 ---> Recursion
int util(vector<vector<int>> &M, int n)
{
    if (n == 0)
        return -1;

    int x = celebrity(M, n - 1);

    if (x == -1)
        return n - 1;

    if (M[x][n - 1] == 1)
        return n - 1;
    if (M[n - 1][x] == 1)
        return x;

    return -1;
}

int celebrity(vector<vector<int>> &M, int n)
{
    int idx = util(M, n);

    if (idx == -1)
        return idx;

    int c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][idx] == 1)
            c1++;
        if (M[idx][i] == 1)
            c2++;
    }

    if (c1 == n - 1 && c2 == 0)
        return idx;
    else
        return -1;
}

// 2 - Pointer Method
int celebrity(vector<vector<int>> &M, int n)
{
    int a = 0, b = n - 1;

    while (a < b)
    {
        if (M[a][b] == 1)
            a++;
        else
            b--;
    }

    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][b] == 1)
            count1++;
        if (M[b][i] == 1)
            count2++;
    }

    if (count1 == n - 1 && count2 == 0)
        return b;
    else
        return -1;
}