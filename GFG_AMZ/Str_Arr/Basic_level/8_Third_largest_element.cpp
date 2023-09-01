// Given an array of distinct elements. Find the third largest element in it.

// Suppose you have A[] = {1, 2, 3, 4, 5, 6, 7}, its output will be 5 because it is the 3 largest element in the array A.

// Example 1:

// Input:
// N = 5
// A[] = {2,4,1,3,5}
// Output: 3

#include <bits/stdc++.h>
using namespace std;

int thirdLargest(int a[], int n)
{
    //O(n log n);
    // sort(a, a + n);
    // return a[n - 3];




    //O(n log k)
    int k=2;
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(a[i]);
    }
    while(k)
    {
        pq.pop();
        k--;
    }
    return pq.top();


}

int main()
{

    int N = 7;
    int A[] = {2, 4, 1, 3, 8, 10, 5};
    cout << thirdLargest(A, N);
}