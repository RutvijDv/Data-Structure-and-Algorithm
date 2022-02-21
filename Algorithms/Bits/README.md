# Bit Magic

1. ***Operators***
    1. AND ( & )
    2. OR ( | )
    3. XOR ( ^ )
    4. Left shift ( << ) —> multiply by 2
    5. Right shift ( >> ) —> divide by 2
    <br />

2. ***Check kth bit set or not of n***
    1. ( n &  ( 1<< ( k-1 ) ) ) ≠ 0
    2. ( n >> (k-1) & 1 ) == 1
    <br />

3. ***Count set bits in n***
    1. Naive solution —> keep shifting the bit right side and count last bit every time.
    2. Brain Kerningan’s Algorithm —> 
        
        while( n>0 ){
        
        n = n&(n-1)
        
        res++;
        
        }
    <br />
        
4. ***Power of 2***
    1. Naive solution —> simple loop and keep check
    2. use Brain Kerningan’s algorithm —→ return ( ( n & ( n-1 ) ) == 0 )
    <br />

5. ***One Odd occuring element***
    1. Naive solution —> use 2 for loops
    2. Effecient solution —> take XOR of all elements, that is answer
        
        x^x = 0, x^x^y = y
    <br />
        
6. ***Missing number in range (1,n)***
    1. solution —> return (1^2^...(n)) ^ (arr[0]^arr[1]^...arr[n-1])
        
        take XOR the (XOR of range) with (XOR of array) 
    <br />    

7. ***Two Odd occuring elements***
    1. Naive solution —> use 2 for loops
    2. efficient solution
        1. int xor = xor of all elements 
        2. xor contains XOR of both odd occuring elements
        3. int sn = xor&(~(xor-1)), this gives the rightmost set bit in our xor hence this bit is set in one odd occuring element and unset in other odd occuring element
        4. int res1=0, res2=0;
        5. travere the array and take xor of every element either in res1 or res2 
        6. if( sn & ele ≠ 0 ) store in res1 else res2, —> basically we are parting array in two groups on basis of that bit is set or not.
        7. print res1 and res2.
    <br />

8. ***Power set of a string using bitwise***