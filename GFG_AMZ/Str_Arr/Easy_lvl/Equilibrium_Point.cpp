#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(long long a[], int n)
{
    int sum = 0;  // Initialize the total sum of the array
    int left = 0; // Initialize the sum of elements to the left

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    // Iterate through the array to find the equilibrium point
    for (int i = 0; i < n; i++)
    {
        sum -= a[i]; // Reduce the total sum by the current element

        // Check if the sum of elements to the left is equal to the remaining sum
        if (sum == left)
        {
            return i + 1; // Equilibrium point found at index i+1
        }
        else
        {
            left += a[i]; // Add the current element to the sum of elements to the left
        }
    }

    return -1; // No equilibrium point found
}

int main()
{
    int n = 5;
    long long A[] = {1, 3, 5, 2, 2};
    cout << equilibriumPoint(A, n);
    return 0;
}

// Given an array A of n positive numbers. The task is to find the first
// equilibrium point in an array. Equilibrium point in an array is a position
// such that the sum of elements before it is equal to the sum of elements after it.

// Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists.

// Example 1:

// Input:
// n = 5
// A[] = {1,3,5,2,2}
// Output:
// 3
// Explanation:
// equilibrium point is at position 3 as sum of elements before it (1+3) =
// sum of elements after it (2+2).
// Example 2:

// Input:
// n = 1
// A[] = {1}
// Output:
// 1
// Explanation:
// Since there's only element hence its only the equilibrium point.