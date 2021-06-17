#include <bits/stdc++.h>
using namespace std;

//Brute Force ---> swapping every odds and evens would be very messy

//Efficient
unsigned int swapBits(unsigned int n)
{
    int odds = n & 0xaaaaaaaa;
    int evens = n & 0x55555555;

    odds = odds >> 1;
    evens = evens << 1;

    return (odds | evens);
}