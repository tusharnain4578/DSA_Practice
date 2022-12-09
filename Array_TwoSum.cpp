#include <iostream>
#include <vector>
#include <map>
using namespace std;
// practice --> https://leetcode.com/problems/two-sum/
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
            return {i, mp[target - nums[i]]};
        mp[nums[i]] = i;
    }
    return {};
}
// Works with negative numbers also
int main()
{
    vector<int> a{-1, -3, -7, -2};
    vector<int> res = twoSum(a, -8);
    cout << a[res[0]] << " " << a[res[1]] << endl;

    return 0;
}

// Another method without map, but takes nlogn time
// vector<int> twoSum(vector<int> &nums, int target)
// {

//     vector<int> res, store;
//     store = nums;

//     sort(store.begin(), store.end());

//     int left = 0, right = nums.size() - 1;
//     int n1, n2;

//     while (left < right)
//     {
//         if (store[left] + store[right] == target)
//         {

//             n1 = store[left];
//             n2 = store[right];

//             break;
//         }
//         else if (store[left] + store[right] > target)
//             right--;
//         else
//             left++;
//     }

//     for (int i = 0; i < nums.size(); ++i)
//     {

//         if (nums[i] == n1)
//             res.emplace_back(i);
//         else if (nums[i] == n2)
//             res.emplace_back(i);
//     }

//     return res;
// }