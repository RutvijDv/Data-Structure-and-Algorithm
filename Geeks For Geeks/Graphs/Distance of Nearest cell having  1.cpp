#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> res(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }

    vector<pair<int, int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty())
    {

        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for (auto moves : move)
        {
            int x = currX + moves.first;
            int y = currY + moves.second;

            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;
            else
            {
                if (res[x][y] > res[currX][currY] + 1)
                {
                    res[x][y] = res[currX][currY] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    return res;
}