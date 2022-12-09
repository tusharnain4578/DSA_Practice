#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // reference ---> https://www.youtube.com/watch?v=jDJuW7tSxio
    // It's a leetcode hard, so better buckle up
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();
    int half_elements = (m + n + 1) / 2;

    int low = 0, high = m;

    while (low <= high)
    {

        int cut1 = (low + high) / 2;
        int cut2 = half_elements - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0;
}

int main()
{
    // vector<int> v1{1, 4, 7, 10, 12};
    // vector<int> v2{2, 3, 6, 15};

    vector<int> v1{1, 3};
    vector<int> v2{2};

    cout << findMedianSortedArrays(v1, v2);

    return 0;
}