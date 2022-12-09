// Most Optimized Algorith with time complexity O(n)
#include <iostream>
#include <vector>
using namespace std;

// practice --> https://leetcode.com/problems/rotate-array/

void reverse(vector<int> &a, int low, int high)
{
    while (low < high)
        swap(a[low++], a[high--]);
}

// RightRotate
void rightRotate(vector<int> &a, int k)
{
    k %= a.size();
    reverse(a, 0, a.size() - k - 1);
    reverse(a, a.size() - k, a.size() - 1);
    reverse(a, 0, a.size() - 1);
}

// LeftRotate
void leftRotate(vector<int> &a, int k)
{
    k %= a.size();
    reverse(a, 0, k - 1);
    reverse(a, k, a.size() - 1);
    reverse(a, 0, a.size() - 1);
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    rightRotate(a, 3);
    for (auto i : a)
        cout << i << " ";

    return 0;
}

// note -> can also do using the stl reverse function
// void rotate(vector<int> &nums, int k)
// {
//     int n = nums.size();

//     k %= n;

//     reverse(nums.begin(), nums.begin() + (n - k));
//     reverse(nums.begin() + (n - k), nums.end());

//     reverse(nums.begin(), nums.end());
// }