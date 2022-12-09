// Elements occurance more than N/3
// Boyer Moore's Voting Algorithm applied

#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/majority-element-ii/
vector<int> majorityElement(int nums[], int n)
{
    // Note* -> There can only exist 2 different numbers at max which exists more than n/3 times in an n size array or there could exist 1 number
    // but not more than 2
    vector<int> ans;

    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;

    for (i = 0; i < n; i++)
    {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
        else if (count1 == 0)
        {
            num1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // now have to confirm
    count1 = count2 = 0;
    for (i = 0; i < n; i++)
    {
        if (nums[i] == num1)
            count1++;
        else if (nums[i] == num2)
            count2++;
    }
    if (count1 > n / 3)
        ans.push_back(num1);
    if (count2 > n / 3)
        ans.push_back(num2);
    return ans;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 2};
    vector<int> majority;
    majority = majorityElement(arr, 5);
    cout << "The majority element is ";

    for (auto it : majority)
    {
        cout << it << " ";
    }
}