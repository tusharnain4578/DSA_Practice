#include <iostream>
#include <vector>
using namespace std;

// practice--> https://leetcode.com/problems/maximum-product-subarray/
long long maxProduct(vector<int> arr, int n)
{
    // reference ---> https://www.youtube.com/watch?v=GbJh0MjUa5U

    // getting max product from left to right traversal
    long long product = 1, max_product = INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            product = 1;
            continue;
        }

        product *= arr[i];
        max_product = max(product, max_product);
    }

    product = 1;
    // getting max product from right to left traversal
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            product = 1;
            continue;
        }
        product *= arr[i];
        max_product = max(product, max_product);
    }
    return max_product;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 0};
    cout << maxProduct(v, v.size());

    return 0;
}

// In leetcode, negative numbers are included, which is not a problem at all, it's just when it's 0 included with them, see below test case for reference

//[-2,0,-1] -> it's answer is 0
// but according to above logic, that will give -1

// to achieve this logic, see below, just use the isZero flag, that's all

// int maxProduct(vector<int> &nums)
// {
//     int product = 1;
//     int ans = INT_MIN;
//     int n = nums.size();

//     bool isZero = false;

//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] == 0)
//         {
//             isZero = true;
//             product = 1;
//             continue;
//         }

//         product *= nums[i];
//         ans = max(ans, product);
//     }

//     product = 1;

//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (nums[i] == 0)
//         {
//             product = 1;
//             continue;
//         }
//         product *= nums[i];
//         ans = max(ans, product);
//     }
//     if (ans < 0 and isZero)
//         return 0;

//     return ans;
// }