#include <bits/stdc++.h>
using namespace std;

void nextGreatest(int arr[], int n)
{
    // code here
    int num = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        arr[i] = num;

        num = max(num, curr);
    }
}

int main()
{
    int Arr[] = {16, 17, 4, 3, 5, 2};
    int n=6;
    nextGreatest(Arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }
}