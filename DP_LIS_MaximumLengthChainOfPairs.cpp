#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/max-length-chain/1

// This dp solution(O(N^2)) will give TLE after, like 100000(1 lakh) testcases 😲
// because there's a greedy solution exists which does this in just O(log(N))
// you can find greedy approach in greedy section of this folder with same problem name

// The structure to use is as follows
struct val
{
    int first;
    int second;
};

// comparator function to sort according to the first number from pair
bool comp(struct val a, struct val b)
{
    return a.second < b.second;
}

// using LIS DP_Optimal tabulation
int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, comp);

    vector<int> lis(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[j].second < p[i].first)
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    return *max_element(lis.begin(), lis.end());
}