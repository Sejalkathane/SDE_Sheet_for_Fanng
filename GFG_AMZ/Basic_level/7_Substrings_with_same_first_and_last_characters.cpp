
// Given string s, the task is to find the count of all substrings
//  which have the same character at the beginning and end.

// Example 1:

// Input: s = "abcab"
// Output: 7
// Explanation: a, abca, b, bcab,
// c, a and b
// Example 2:

// Input: s = "aba"
// Output: 4
// Explanation: a, b, a and aba

#include <bits/stdc++.h>
using namespace std;

int countSubstringWithEqualEnds(string s)
{
    // Your code goes here
    int n = s.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    unordered_map<char, int> mp;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        //correct way ::
        if (mp[s[i]])
        {
            ans += mp[s[i]];
        }
        mp[s[i]]++;
    }

    return ans;
}

int main()
{
    string s = "abcab";

    cout << countSubstringWithEqualEnds(s);

    return 0;
}