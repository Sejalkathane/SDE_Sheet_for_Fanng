#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.size();

    // Check if the input strings are equal, return s if they are.
    if (s == t)
    {
        return s;
    }

    // Create a map to store the frequency of characters in string t.
    unordered_map<int, int> mp;

    // Count the characters in string t and store their frequencies in the map.
    for (auto i : t)
    {
        mp[i]++;
    }

    // Initialize 'count' with the number of distinct characters in t.
    int count = mp.size();

    // Initialize pointers and variables to track the minimum window substring.
    int i = 0, j = 0;
    int start = 0;
    int mini = INT_MAX;

    // Iterate through the string s.
    while (j < n)
    {
        // Check if the current character is in the map.
        if (mp.find(s[j]) != mp.end())
        {
            // Decrease the count of the character's occurrence.
            mp[s[j]]--;

            // If the character's count reaches 0, decrease the total count of distinct characters.
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }

        // Check if all distinct characters from t are in the current window.
        while (count == 0)
        {
            // Update the minimum window if the current window size is smaller.
            if (mini > j - i + 1)
            {
                mini = j - i + 1;
                start = i;
            }

            // Shrink the window by moving the left pointer i.
            if (mp.find(s[i]) != mp.end())
            {
                // if we get in map then we increment it
                mp[s[i]]++;
                // if it increment and greater than 0 then count also increase help to remove 
                    //   duplicasy if one is present and keep element constant
                if (mp[s[i]] > 0)
                {
                    count++;
                }
            }
            //help to srink window
            i++;
        }

        // Expand the window by moving the right pointer j.
        j++;
    }

    // If no valid window is found, return an empty string.
    if (mini == INT_MAX)
    {
        return "";
    }

    // Return the minimum window substring.
    return s.substr(start, mini);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);

    return 0;
}

// Given two strings s and t of lengths m and n respectively,
//     return the minimum window substring
//         of s such that every character in
//         t(including duplicates)
//             is included in the window.If there is no such substring,
//     return the empty string "".

//            The testcases will be generated such that the answer is unique.

//            Example 1 :

//     Input : s = "ADOBECODEBANC",
//             t = "ABC" Output : "BANC" Explanation : The minimum window substring "BANC" includes 'A', 'B', and'C' from string t.Example 2 :

//     Input : s = "a",
//             t = "a" Output : "a" Explanation : The entire string s is the minimum window.Example 3 :

//     Input : s = "a",
//             t = "aa" Output : "" Explanation : Both 'a' s from t must be included in the window.Since the largest window of s only has one 'a', return empty string.