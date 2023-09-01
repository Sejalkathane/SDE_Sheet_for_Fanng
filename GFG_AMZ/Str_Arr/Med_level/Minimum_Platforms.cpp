#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    int n = arr.size();

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({arr[i], dep[i]});
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++)
    {
         //push departure time in pq ;
        pq.push(v[i].second);
        //in pq only remin train are left and remning train leftt the platform
        // pq top less than our first means means 1st train leave platform already ew can go there
        if(pq.top()<v[i].first) pq.pop();

    }
    cout<<pq.size();
}

// Given arrival and departure times of all trains that reach a railway
//  station. Find the minimum number of platforms required for the railway
//  station so that no train is kept waiting.

// Consider that all the trains arrive on the same day and leave on the
// same day. Arrival and departure time can never be the same for a train but
// we can have arrival time of one train equal to departure time of the other.
//  At any given instance of time, same platform can not be used for both
//  departure of a train and arrival of another train. In such cases, we need
//   different platforms.

// Example 1:
// Input: n = 6
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation:
// Minimum 3 platforms are required to
// safely arrive and depart all trains.

// Example 2:
// Input: n = 3
// arr[] = {0900, 1100, 1235}
// dep[] = {1000, 1200, 1240}
// Output: 1
// Explanation: Only 1 platform is required to
// safely manage the arrival and departure
// of all trains.