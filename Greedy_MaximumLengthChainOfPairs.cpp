#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/max-length-chain/1

// reference --> https://www.youtube.com/watch?v=SDtqTXisPIc

// Most efficient approach using greedy, O(N*log(N))
// There also exists a DP way (LIS), but that will give tle (most probably), atleast on the above practice link

// The structure to use is as follows
struct val
{
    int first;
    int second;
};

// comparator function to sort according to the second number from pair
// you have to sort acc to second only, see reference if you want
bool comp(struct val a, struct val b)
{
    return a.second < b.second;
}

int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, comp);

    int prev = p[0].second;

    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        if (p[i].first > prev)
        {
            ans++;
            prev = p[i].second;
        }
    }

    return ans;
}