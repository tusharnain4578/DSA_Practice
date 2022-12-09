#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/3sum/

// This is the 2 pointer approach, but you have to sort the array for this
// for the approach with uses the hashmap, you can find that on the 4sum code in this folder

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < (int)(nums.size() - 2); i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {

            int sum = 0 - nums[i];
            int low = i + 1;
            int high = (int)(nums.size() - 1);

            while (low < high)
            {
                if (nums[low] + nums[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    res.push_back(temp);

                    while (low < high && nums[high] == nums[high - 1])
                        high--;

                    while (low < high && nums[low] == nums[low + 1])
                        low++;

                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] > sum)
                    high--;
                else
                    low++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> v{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(v);

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