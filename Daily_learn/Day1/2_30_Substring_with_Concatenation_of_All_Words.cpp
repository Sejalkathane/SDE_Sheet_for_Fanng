#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
    unordered_map<string, int> counts;
    for (string word : words)
    {
        counts[word]++;
    }
    vector<int> indexes;
    if (s.empty() || words.empty())
    {
        return indexes;
    }
    if (s == "")
    {
        return indexes;
    }

    int n = s.length(), num = words.size(), len = words[0].length();

    for (int i = 0; i < n - num * len + 1; i++)
    {
        unordered_map<string, int> seen;
        int j = 0;

        for (; j < num; j++)
        {
            string word = s.substr(i + j * len, len);

            if (counts.find(word) != counts.end())
            {
                seen[word]++;
                if (seen[word] > counts[word])
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        if (j == num)
        {
            indexes.push_back(i);
        }
    }

    return indexes;
}

int main()
{

   string s = "barfoothefoobarman";
   vector<string >words = {"foo","bar"};
   vector<int>ans=findSubstring(s,words);
   for(int i=0;i<ans.size();i++)
   {
    cout<<ans[i]<<" ";
   }
    return 0;
}

// You are given a string s and an array of strings words. All the strings of
// words are of the same length.

// A concatenated substring in s is a substring that contains all the strings of any
//  permutation of words concatenated.

// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab",
// "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring
// because it is not the concatenation of any permutation of words.

// Return the starting indices of all the concatenated substrings in s. You can return
// the answer in any order.

// Example 1:

// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Since words.length == 2 and words[i].length == 3, the concatenated
// substring has to be of length 6.

// The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"]
// which is a permutation of words.

// The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"]
//  which is a permutation of words.

// The output order does not matter. Returning [9,0] is fine too.
// Example 2:

// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []
// Explanation: Since words.length == 4 and words[i].length == 4, the concatenated
// substring has to be of length 16.

// There is no substring of length 16 is s that is equal to the concatenation of any
//  permutation of words.
// We return an empty array.