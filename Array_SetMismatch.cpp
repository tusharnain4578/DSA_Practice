#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// practice ---> https://leetcode.com/problems/set-mismatch/

// LC Easy

vector<int> findErrorNums(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> s;
    vector<int> ans;
    int sum = 0;
    for (const int &i : nums)
    {
        if (s.find(i) != s.end())
            ans.push_back(i);
        else
        {
            s.insert(i);
            sum += i;
        }
    }

    int perfectSum = n * (n + 1) / 2;

    ans.push_back(perfectSum - sum);

    return ans;
}