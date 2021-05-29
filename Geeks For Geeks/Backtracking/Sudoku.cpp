#include <bits/stdc++.h>
using namespace std;

bool isSafe(int grid[N][N], int i, int j, int x)
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

bool SolveSudoku(int grid[N][N])
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
        if (isSafe(grid, i, j, x))
        {
            grid[i][j] = x;
            if (SolveSudoku(grid))
                return true;
            grid[i][j] = 0;
        }
    }

    return false;
}

//Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
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