#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> maze[], int i, int j, int N)
{
    return i < N && j < N && maze[i][j] != 0;
}

bool solve(vector<int> maze[], int n, int x, int y, vector<vector<int>> &sol)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, n))
    {
        int jump = maze[x][y];
        sol[x][y] = 1;

        if (solve(maze, n, x, y + 1, sol))
            return true;
        if (solve(maze, n, x + 1, y, sol))
            return true;

        sol[x][y] = 0;
    }

    return false;
}

void solve(int N, vector<int> maze[])
{
    vector<vector<int>> sol(N, vector<int>(N, 0));
    if (!solve(maze, N, 0, 0, sol))
    {
        cout << "-1" << endl;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return;
}