#include <bits/stdc++.h>
using namespace std;

//Naive approach ---> Simply Sort the array

//Better approach ---> count the number of 0s and place them (requires 2 traversals of array)

//Better approach
void sort01(int arr[], int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        while (arr[left] == 0 && left < right)
            left++;

        while (arr[right] == 1 && right < right)
            right--;

        if (left < right)
            swap(arr[left++], arr[right--]);
    }
    return;
}

//Efficient Algorithm ---> 2 pointer Algorithm or say Dutch National flag Algorithm

void sort01(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        switch (arr[low])
        {

        case 0:
            low++;
            break;

        case 1:
            swap(arr[low++], arr[high--]);
            break;
        }
    }
    return;
}