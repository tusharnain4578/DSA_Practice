#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    // reference --> https://www.youtube.com/watch?v=WFNa5o-dHGo&t=1440s
    //  some edge cases
    if (nums.size() == 1)
        return nums[0];
    else if (nums[0] != nums[1])
        return nums[0];
    else if (nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];

    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if (nums[mid] == nums[mid - 1])
        {
            int left_count = mid - low + 1;
            if (left_count % 2 == 0)
                low = mid + 1;
            else
                high = mid - 2;
        }
        else if (nums[mid] == nums[mid + 1])
        {
            int right_count = high - mid + 1;
            if (right_count % 2 == 0)
                high = mid - 1;
            else
                low = mid + 2;
        }
    }
    return 0;
}

int main()
{
    vector<int> v{3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(v);

    return 0;
}