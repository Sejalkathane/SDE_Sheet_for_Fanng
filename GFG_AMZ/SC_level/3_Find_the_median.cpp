// Find the median

#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
    // Code here.
    sort(v.begin(), v.end());
    int n = v.size();
    int mid = n / 2;
    if (n % 2 != 0)
        return v[mid];
    else
    {
        int a = n / 2;
        int b = a - 1;
        int c = (v[a] + v[b]) / 2;
        return c;
    }
    return 0;
}

int main()
{
    vector<int> v = {90, 100, 78, 89, 67};
    cout << find_median(v);
}