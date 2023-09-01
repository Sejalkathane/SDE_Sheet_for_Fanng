
// Given a string S, write a program to count the occurrence of Lowercase characters, Uppercase characters, Special characters and Numeric values in the string.
// Note: There are no white spaces in the string.

// Example 1:

// Input:
// S = "#GeeKs01fOr@gEEks07"
// Output:
// 5
// 8
// 4
// 2
// Explanation: There are 5 uppercase characters,
// 8 lowercase characters, 4 numeric characters
// and 2 special characters.


#include <bits/stdc++.h>
using namespace std;

vector<int> count(string s)
{
    int lowercase = 0;
    int uppercase = 0;
    int special_char = 0;
    int numeric = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            lowercase++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            uppercase++;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            numeric++;
        }
        else
        {
            special_char++;
        }
    }

    vector<int> ans = {uppercase, lowercase, numeric, special_char};
    return ans;
}

int main()
{
  string S="#GeeKs01fOr@gEEks07";

  vector<int>ans=count(S);

  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }

    return 0;
}