#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &vis)
{
    int n = grid.size();
    if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y] || grid[x][y] == 0)
        return false;

    int cell = grid[x][y];
    vis[x][y] = true;

    if (cell == 2)
        return true;
    if (cell == 3 || cell == 1)
    {
        if (dfs(grid, x - 1, y, vis) || dfs(grid, x + 1, y, vis) || dfs(grid, x, y - 1, vis) || dfs(grid, x, y + 1, vis))
            return true;
        return false;
    }
}

bool is_Possible(vector<vector<int>> &grid)
{
    int n = grid.size(), x, y;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                x = i;
                y = j;
            }
        }
    }

    if (dfs(grid, x, y, vis))
        return true;
    else
        return false;
}