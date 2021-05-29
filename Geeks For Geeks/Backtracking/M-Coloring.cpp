#include <bits/stdc++.h>
using namespace std;

bool isSafe(bool graph[101][101], int node, int V, int j, vector<int> &marked)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[i][node] && marked[i] == j)
        {
            return false;
        }
    }
    return true;
}

bool permute(bool graph[101][101], int node, int V, int m, vector<int> &marked)
{
    if (node == V)
        return true;

    for (int j = 1; j <= m; j++)
    {
        if (isSafe(graph, node, V, j, marked))
        {
            marked[node] = j;
            if (permute(graph, node + 1, V, m, marked))
                return true;
            marked[node] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> marked(V, 0);

    return permute(graph, 0, V, m, marked);
}