#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<bool>> &board, int row, int col, int n)
{
    int i, j;

    for (i = 1; i <= row; i++)
        if (board[i][col])
            return false;

    for (i = row, j = col; i > 0 && j > 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i > 0 && j <= n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

void solve(vector<vector<bool>> &grid, vector<vector<int>> &res, vector<int> temp, int idx, int n)
{

    if (idx == (n + 1))
    {
        res.push_back(temp);
        return;
    }

    for (int i = 1; i <= n; i++)
    {

        if (isSafe(grid, idx, i, n) == true)
        {
            grid[idx][i] = true;
            temp.push_back(i);
            solve(grid, res, temp, idx + 1, n);
            temp.pop_back();
        }
        grid[idx][i] = false;
    }

    return;
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> res;
    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    vector<int> temp;

    solve(grid, res, temp, 1, n);

    return res;
}