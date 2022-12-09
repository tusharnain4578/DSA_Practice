#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/contains-duplicate/

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> s;

    for (auto const &i : nums)
    {
        if (s.find(i) != s.end())
            return true;
        s.insert(i);
    }

    return false;
}