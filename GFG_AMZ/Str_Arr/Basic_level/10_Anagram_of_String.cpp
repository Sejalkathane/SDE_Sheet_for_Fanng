#include <bits/stdc++.h>
using namespace std;

// Given two strings S1 and S2 in lowercase, the task is to make
// them anagram. The only allowed operation is to remove a character
// from any string. Find the minimum number of characters to be deleted to
// make both the strings anagram. Two strings are called anagram of each other if
// one of them can be converted into another by rearranging its letters.

// Example 1:

// Input:
// S1 = bcadeh
// S2 = hea
// Output: 3
// Explanation: We need to remove b, c
// and d from S1.

int remAnagram(string str1, string str2)
{
    unordered_map<char, int> mp;

    for (auto i : str1)
    {
        mp[i]++;
    }
    for (auto i : str2)
    {
        mp[i]--;
    }

    int ans = 0;
    for (auto a : mp)
    {
        ans += abs(a.second);
    }

    return ans;
}

int main()
{
    string S1 = "bcadeh";
    string S2 = "hea";
    cout<<remAnagram(S1,S2);
    return 0;
}