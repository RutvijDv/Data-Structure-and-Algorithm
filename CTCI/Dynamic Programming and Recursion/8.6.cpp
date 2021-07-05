#include <bits/stdc++.h>
using namespace std;

long long toh(int N, int from, int to, int aux)
{
    toh(N - 1, from, aux, to);

    cout << "move disk " << N << " from rod " << from << " to rod " << to;

    toh(N - 1, aux, to, from);

    return 1;
}