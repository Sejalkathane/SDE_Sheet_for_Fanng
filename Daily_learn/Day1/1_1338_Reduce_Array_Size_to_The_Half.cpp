#include <bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& arr) {
   
   // Initialize the frequency requirement as half of the array size
    int k = (arr.size()) / 2; 

   // Create a map to count the frequency of elements
    unordered_map<int, int> mp; 

    for (auto a : arr) {
        mp[a]++; // Count the frequency of each element
    }

    priority_queue<int> pq; 
    for (auto a : mp) {
        pq.push(a.second); // Push the frequencies into the priority queue
    }

    int count = 1; // Initialize the count of removed elements

    // Iterate until the priority queue is empty
    while (!pq.empty()) 
    {
        // Get the highest frequency from the priority queue
        int a = pq.top(); 

        // If the frequency of current element is smaller than the remaining requirement
        if (a < k) 
        {
            k = k - a; // Update the remaining requirement
            count++; // Increment the count of removed elements
            pq.pop(); // Remove the current element's frequency from the queue
        }
        // If the remaining requirement is smaller than the current frequency
        else if (k < a) {
            count++; // Increment the count of removed elements
            return count - 1; // Return the count of removed elements minus one
        }
        // If the remaining requirement matches the current frequency
        else {
            //handel {1,2,3,4,5,6,7,8,9,10} that way return count
            return count; // Return the count of removed elements
        }
    }

    return count; // Return the count of removed elements
}

int main()
{
    vector<int>arr={3,3,3,3,5,5,5,2,2,7};
    cout<<minSetSize(arr);
    return 0;
}

// You are given an integer array arr. You can choose a set of integers
//  and remove all the occurrences of these integers in the array.

// Return the minimum size of the set so that at least half of the integers
//  of the array are removed.

// Example 1:

// Input: arr = [3,3,3,3,5,5,5,2,2,7]
// Output: 2
// Explanation: Choosing {3,7} will make the new array [5,5,5,2,2]
//  which has size 5 (i.e equal to half of the size of the old array)

// Possible sets of size 2 are {3,5},{3,2},{5,2}.

// Choosing set {2,7} is not possible as it will make the new array
//  [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
// Example 2:

// Input: arr = [7,7,7,7,7,7]
// Output: 1
// Explanation: The only possible set you can choose is {7}.
//  This will make the new array empty.