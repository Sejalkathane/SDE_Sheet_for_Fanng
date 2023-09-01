#include <bits/stdc++.h>
using namespace std;

int lenOfLongIncSubArr(int arr[], int n)
{
    int count = 1;
    int maxi = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
            maxi = max(count, maxi);
        }
        else
        {
            count = 1;
        }
    }
    return maxi;
}

int main()
{
    int n = 10;
    int arr[] = {12, 13, 1, 5, 4, 7, 8, 10, 10, 11};
   cout<< lenOfLongIncSubArr(arr, n);
    return 0;
}