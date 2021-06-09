#include <bits/stdc++.h>
using namespace std;

//We will rotate matrix in anticlockwise

//using O(n*n) space
void rotateby90(vector<vector<int>> &matrix, int n)
{
    int rotated[n][n] = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[n - j - 1][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rotated[i][j];
        }
    }

    return;
}

//In Place --> convert to transpose and them exchange rows

void rotateby90(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }

    return;
}

//Best Solution InPlace ---> Single pass
void rotateby90(vector<vector<int>> &mat, int n)
{
    for (int x = 0; x < n / 2; x++)
    {
        for (int y = x; y < n - x - 1; y++)
        {
            swap(mat[x][y], mat[y][n - x - 1]);
            swap(mat[y][n - x - 1], mat[n - x - 1][n - y - 1]);
            swap(mat[n - x - 1][n - y - 1], mat[n - y - 1][x]);
        }
    }
    return;
}