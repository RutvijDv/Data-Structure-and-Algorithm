# String

String can be stored in two ways, i) c style string (array based) ii) Class based string 

1. ***Components of string class in c++***
    1. .length()
        
        return length
        
    2. .find(”eek”)
        
        returns first index where match is found
        
    3. .substr(stra_index, length)
        
        return that particular substring
        
    4. string::npos
        
        when searching some substring in a given string, and we dont find it, string.find() return string::npos, hence it can be used to match in if statement. if(xyz.find(’eek’) == string::npos). 
        
    5. cin>>str
        
        takes the input till a white space is detected.
        
    6. getline(cin, str)
        
        takes input untill enter is hit. getline(cin, str, ‘a) takes input till ‘a’ is detetcted. 
        <br />
        
    
2. ***Palindrome check***  ( a string is said to be palindrome if reverse of the string is same as string )
    1. Naive approach → reverse the string and check → O(n) complexity
    2. Effecient approach → start matching elements from front and back → O(n/2) comlpexity
    <br />
    
3. ***Subsequence check***  ( a string that can be created by removing some characters of other string )
    1. Naive approach → create superset of the string s1 and then match the every element in superset with s2. → O(2^n) * O(n) complexity = O(2^n * n)
    2. Effecient approach → keep matching the element in s2 with element of s1, if matched increase the counter else continue. At the end if counter becomes of length s2 return true else false. → O(n) time complexity
    3. Recursive approach → func(s1, s2, n, m) → n is length of s1, m is length of s2
        
        In this approach we will be matching the last character in every recursive call. If matched, pass recursive call decreaseing length in both strings, else decrease length in s1 string only. → O(n) time complexity, O(n) space complexity
        
        Algorithm
        
        - if (m == 0) return true
        - if (n == 0) return false
        - if (s1[n-1] == s2[m-1]) return func(s1, s2, n-1, m-1);
        - if(s1[n-1] ≠ s2[m-1]) return func(s1, s2, n-1, m);
        <br />
        
4. ***Anagram check** ( **a string that's formed by rearranging the letters of another string )***
    1. Naive approach → sort both strings and compare them → O(nlogn) time complexity
    2. Effecient approach → use unordered_map to store frequency of characters.
    <br />
    
5. ***Leftmost Repeating Character***
    1. Naive approch - For each character from start check if it reappears in the remaining string (succeding). → O(n^2) complexity
    2. Efiicient approach 1 - use unordered map to store the frequency of every element and check accordingly. → O(n) time complexity and O(1) space complexity.
    3. Efficient approach 2 -  use unordered map to store the first occurence of a character in the string. If any of the character reappears then store the minimum index in result variable. → O(n) time complexity O(1) space complexity
    <br />
    
6. ***Leftmost non-repeating element***
    1. Naive approach - For every character check if it is present again in the complete string (preceeding and succeding) → O(n^2) time complexity.
    2. Efficient approach 1 -  use unordered map to store the frequency of every element and traverse the string again to get the leftmost non repeating element. → O(n) time complexity and O(1) space complexity.
    3. Efficient approach 2 - use unordered map for characters state where states are as follows - 
        1. -1 : did not appear
        2. -2 : appeared more than once
        3.   i : index of the only occurence of elements.
        
        Taverse the unordered map to get the minimum index. → O(n) time complexity O(1) space complexity.
        <br />
        
7. ***Reverse words in a string***
    1. Naive approach - Create stack and push each word into a stack. Pop the words and print them.
    2. Efficient approach - Reverse the whole string and then reverse individual words.
        1. reverse(str.begin()+startIndex, str.begin()+endIndex)
        <br />
        
8. ***Pattern Searching***
    1. Naive approach - Travese through the main string if the character matches to the first character of the pattern. Check the occurence of pattern for that index in the main string. → time complexity (O(n-m)*O(m))
    2. Rabin Karp algorithm - Store the pattern string into a hash. Now traverse the main string and for each substring of size m from the current index compare its hash with the patter hash. If both are equal the pattern exists in the string. Algorithm (let m be pattern length and n be the text length) : → time complexity (O(n-m)*O(m))
        1. Create a hash set and push pattern into it
        2. for each substring of length m in main string check whether the subtring exist in the set.
        3. If substring exists return true. Else return false.
    <br />

9. ***Check Rotations ( s1 is rotation of s2 or not )***
    1. Naive approach - rotate one of the string at every index and match with other → time complexity O(n^2), space complexity O(n) for storing string after rotation.
    2. Effecient approach - (s1+s1).find(s2) → time complexity O(n) using the library function, space complexity O(n) - for concatening the string.
    <br />
    
10. ***Search Anagrams***
    1. Naïve approach - For every substring of length m in main string check whether the substring and the pattern strings are anagrams of each other. → O((n-m+1)*m) time complexity O(1) space complexity.
    2. Efficient approach - Maintain two maps to store the frequency of characters in pattern and substring of size m from the main string. For each substring of size m from the main string update the values in the map ( add frequency of new char and decrease the frequency of first char in curr substr ) and compare the two maps. → O(n) time complexity O(1) space complexity.
    <br />
    
11. ***Longest Substring with Distinct Characters***
    
    Refer GFG videos DSA course