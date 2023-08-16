#include <bits/stdc++.h>
using namespace std;

string firstAlphabet(string s)
{
    int n = s.size();
    if (n == 0)
        return "";

    string ans = "";
    int t = true;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && t == true)
        {
            t = false;
            ans += s[i];
        }
        if (s[i] == ' ')
        {
            ans += s[i + 1];
        }
    }
    return ans;
}

int main()
{
     string s="geeks for geeks"; 
     cout<<firstAlphabet(s);
    return 0;
}