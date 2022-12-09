#include <iostream>
#include <vector>
using namespace std;

// practice --> https://leetcode.com/problems/merge-sorted-array/

// The merged array should be set into nums1 -> Leetcode condition
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // Note -> just reverse of the normal algorithm of merging two sorted arrays
    int pt1 = m - 1, pt2 = n - 1, pt = m + n - 1;

    while (pt1 >= 0 and pt2 >= 0)
    {
        if (nums1[pt1] > nums2[pt2])
            nums1[pt--] = nums1[pt1--];
        else
            nums1[pt--] = nums2[pt2--];
    }

    while (pt1 >= 0)
    {
        nums1[pt--] = nums1[pt1--];
    }
    while (pt2 >= 0)
    {
        nums1[pt--] = nums2[pt2--];
    }
}

int main()
{
    vector<int> nums1{1, 3, 5, 7, 0, 0, 0, 0};
    vector<int> nums2{2, 4, 6, 8};
    merge(nums1, 4, nums2, nums2.size());

    for (const int &i : nums1)
        cout << i << " ";
    return 0;
}

//