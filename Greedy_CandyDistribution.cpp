#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// practice --> https://leetcode.com/problems/candy/

int candy(vector<int> &ratings)
{
    // reference --> https://www.youtube.com/watch?v=h6_lIwZYHQw

    int n = ratings.size();

    vector<int> v(n, 1); // 1 candies to everyone

    for (int i = 1; i < n; i++) // left to right
    {
        if (ratings[i] > ratings[i - 1])
            v[i] = v[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) // right to left
    {
        if (ratings[i] > ratings[i + 1])
            v[i] = max(v[i], v[i + 1] + 1);
    }

    return accumulate(v.begin(), v.end(), 0);
}