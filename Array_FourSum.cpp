#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/4sum/
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // reference --> https://www.youtube.com/watch?v=OZdOHiodh_c
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int tsum = target - (nums[i] + nums[j]);

            int low = j + 1;
            int high = n - 1;
            while (low < high)
            {
                if (nums[low] + nums[high] == tsum)
                {
                    ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;

                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < tsum)
                    low++;
                else
                    high--;
            }
        }
    }
    return ans;
}

int main()
{
    // vector<int> v{1, 0, -1, 0, -2, 2};s
    vector<int> v{0};
    int target = 0;
    vector<vector<int>> ans = fourSum(v, target);

    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

// If you're getting integer overflow error on leetcode, you can see the below reference

// vector<vector<int>> fourSum(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     vector<vector<int>> ans;

//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < n - 3; i++)
//     {
//         if (i > 0 and nums[i] == nums[i - 1])
//             continue;

//         long long tsum1 = target - nums[i];

//         for (int j = i + 1; j < n - 2; j++)
//         {
//             if (j > i + 1 and nums[j] == nums[j - 1])
//                 continue;

//             long long tsum2 = tsum1 - nums[j];

//             int left = j + 1, right = n - 1;

//             while (left < right)
//             {
//                 if (nums[left] + nums[right] == tsum2)
//                 {
//                     ans.push_back({nums[i], nums[j], nums[left], nums[right]});

//                     while (left < right and nums[left] == nums[left + 1])
//                         left++;
//                     while (left < right and nums[right] == nums[right - 1])
//                         right--;

//                     left++, right--;
//                 }
//                 else if (nums[left] + nums[right] < tsum2)
//                     left++;
//                 else
//                     right--;
//             }
//         }
//     }

//     return ans;
// }