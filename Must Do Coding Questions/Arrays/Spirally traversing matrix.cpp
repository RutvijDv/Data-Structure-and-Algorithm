#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    vector<int> res;
    int rmin = 0, cmin = 0, rmax = r, cmax = c;
    while (rmin < rmax && cmin < cmax)
    {

        for (int i = cmin; i < cmax; i++)
        {
            res.push_back(matrix[rmin][i]);
        }

        for (int i = rmin + 1; i < rmax; i++)
        {
            res.push_back(matrix[i][cmax - 1]);
        }

        if (rmax - 1 != rmin)
        {
            for (int i = cmax - 2; i >= cmin; i--)
            {
                res.push_back(matrix[rmax - 1][i]);
            }
        }

        if (cmin != cmax - 1)
        {
            for (int i = rmax - 2; i >= rmin + 1; i--)
            {
                res.push_back(matrix[i][cmin]);
            }
        }

        rmin++;
        rmax--;
        cmin++;
        cmax--;
    }

    return res;
}