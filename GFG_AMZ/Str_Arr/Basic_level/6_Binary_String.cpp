#include <bits/stdc++.h>
using namespace std;

long binarySubstring(int n, string a)
{
    long long one = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            one++;
        }
    }

    long long cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            one--;
            cnt = cnt + one;
        }
    }
    return cnt;
}

int main()
{
    int n=84;
    string s="011110011010110000010110001111000111010111101001010100100011101010111010101001010000";

    cout<<binarySubstring(n,s);
    return 0;
}