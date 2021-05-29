#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> grid, int N, int i, int j, int x)
{
    for (int k = 0; k < N; k++)
    {
        if (grid[i][k] == x || grid[k][j] == x)
            return false;
    }

    int s = sqrt(N);
    int is = i - i % s;
    int js = j - j % s;

    for (int l = is; l < is + s; l++)
    {
        for (int m = js; m < js + s; m++)
        {
            if (grid[l][m] == x)
                return false;
        }
    }

    return true;
}

bool SolveSudoku(vector<vector<int>> grid, int N)
{
    int i, j;
    bool flag = false;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    if (i == N && j == N)
        return true;

    for (int x = 1; x <= N; x++)
    {
        if (isSafe(grid, N, i, j, x))
        {
            grid[i][j] = x;
            if (SolveSudoku(grid, N))
                return true;
            grid[i][j] = 0;
        }
    }

    return false;
}

void printGrid(vector<vector<int>> grid, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
    return;
}