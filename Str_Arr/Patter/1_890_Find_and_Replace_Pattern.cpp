// Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

// Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

// Example 1:

// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
// Example 2:

// Input: words = ["a","b","c"], pattern = "a"
// Output: ["a","b","c"]

//::::::::::::::::::;
// to solve this problem idea is to put number to every diffrent in manner like if aab then  112
//  abcd =1234 in vector
// let's see implementation:

#include <bits/stdc++.h>
using namespace std;

vector<int> found_pat(string pat)
{
    if (pat.size() == 0)
        return {};

    unordered_map<char, int> mp;
    vector<int> v;

    int ind = 0;
    for (int i = 0; i < pat.size(); i++)
    {
        // not found in map;
        if (mp.find(pat[i]) == mp.end())
        {
            mp.insert({pat[i], ind++});
            v.push_back(mp[pat[i]]);
        }
        // pattern found simple push it same number in vector
        else
        {
            v.push_back(mp[pat[i]]);
        }
    }

    return v;
}

int main()
{
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";

    int n = words.size();

    vector<int> pat = found_pat(pattern);

    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        vector<int> word_pat = found_pat(words[i]);

        if (pat == word_pat)
        {
            ans.push_back(words[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}