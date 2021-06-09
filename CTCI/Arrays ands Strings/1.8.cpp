#include <bits/stdc++.h>
using namespace std;

//Brute Force --> Make another matrix and keep flags for zero

//keep track of rows and cols to be zero in a vector
void nullifyRow(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        matrix[row][i] = 0;
    }
    return;
}

void nullifyCol(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        matrix[i][col] = 0;
    }
    return;
}

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<bool> rows(n, false);
    vector<bool> cols(m, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (rows[i])
            nullifyRow(matrix, i, m);
    }

    for (int i = 0; i < m; i++)
    {
        if (cols[i])
            nullifyCol(matrix, n, i);
    }
    return;
}

//use bitset to store rows and cols to be zero
void nullifyRow(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        matrix[row][i] = 0;
    }
    return;
}

void nullifyCol(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        matrix[i][col] = 0;
    }
    return;
}

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bitset<200> bsetrow;
    bitset<200> bsetcol;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                bsetrow[i] = 1;
                bsetcol[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (bsetrow[i])
            nullifyRow(matrix, i, m);

    for (int i = 0; i < m; i++)
        if (bsetcol[i])
            nullifyCol(matrix, n, i);

    return;
}

//With O(1) space

void nullifyRow(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        matrix[row][i] = 0;
    }
    return;
}

void nullifyCol(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        matrix[i][col] = 0;
    }
    return;
}

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool isFirstRow = false;
    bool isFirstCol = false;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            isFirstCol = true;
            break;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (matrix[0][i] == 0)
        {
            isFirstRow = true;
            break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            nullifyRow(matrix, i, m);
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (matrix[0][i] == 0)
        {
            nullifyCol(matrix, n, i);
        }
    }

    if (isFirstRow)
        nullifyRow(matrix, 0, m);
    if (isFirstCol)
        nullifyCol(matrix, n, 0);

    return;
}