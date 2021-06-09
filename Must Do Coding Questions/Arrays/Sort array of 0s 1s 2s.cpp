#include <bits/stdc++.h>
using namespace std;

//Naive approach ---> Simply Sort the array

//Better approach ---> count the number of 0s 1s and place them (requires 2 traversals of array)

//Efficient Algorithm ---> 3 pointer Algorithm or say Dutch National flag Algorithm

void sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        switch (arr[mid])
        {

        case 0:
            swap(arr[mid++], arr[low++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
    return;
}