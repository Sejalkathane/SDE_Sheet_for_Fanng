#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int it = k - arr[i];

        // if it present in map
        if (mp[it])
        {
            count += mp[it];
        }

        mp[arr[i]]++;
    }
    return count;
}

int main()
{
    int n=4;
    int a[]={1,5,7,1};
    int k=6;
    cout<<getPairsCount(a,n,k);
    return 0;
}
