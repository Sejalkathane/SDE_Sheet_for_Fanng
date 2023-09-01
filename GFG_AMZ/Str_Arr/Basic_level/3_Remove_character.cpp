
// Given two strings string1 and string2, remove those characters from
//  first string(string1) which are present in second string(string2).
//   Both the strings are different and contain only lowercase characters.
// NOTE: Size of  first string is always greater than the size of  second string( |string1| > |string2|).

// Example 1:

// Input:
// string1 = "computer"
// string2 = "cat"
// Output: "ompuer"
// Explanation: After removing characters(c, a, t)
// from string1 we get "ompuer".
// Example 2:

// Input:
// string1 = "occurrence"
// string2 = "car"
// Output: "ouene"
// Explanation: After removing characters
// (c, a, r) from string1 we get "ouene".

#include <bits/stdc++.h>
using namespace std;

string removeChars(string s1, string string2)
{

    set<char> st;
    for (auto i : string2)
    {
        st.insert(i);
    }

    string ans = "";
    for (int i = 0; i < s1.size(); i++)
    {
        if (st.find(s1[i]) == st.end())
        {
            ans += s1[i];
        }
    }
    return ans;
}

int main()
{
    string s1 = "occurrence";
    string s2 = "car";

    cout << removeChars(s1, s2);
}