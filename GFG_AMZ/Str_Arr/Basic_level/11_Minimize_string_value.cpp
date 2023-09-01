#include <bits/stdc++.h>
using namespace std;

int minValue(string S, int k)
{
    unordered_map<char, int> freq;

    for (char c : S)
    {
        freq[c]++;
    }

    priority_queue<int> pq;

    for (auto kv : freq)
    {
        pq.push(kv.second);
    }

    while (k > 0 && !pq.empty())
    {
        int a = pq.top();
        pq.pop();
        a--;
        if (a > 0)
        {
            pq.push(a); // Update the new frequency after decrementing
        }
        k--;
    }

    int sum = 0;

    while (!pq.empty())
    {
        int t = pq.top();
        pq.pop();
        sum += t * t;
    }

    return sum;
}

int main()
{
    int k=6;
    string S="aaaabccc";
    cout<<minValue(S,k);
    return 0;
}