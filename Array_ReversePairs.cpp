#include <iostream>
#include <vector>
using namespace std;

// practice --> https://leetcode.com/problems/reverse-pairs/
int merge(vector<int> &a, int low, int high)
{
    int count = 0;
    int mid = (low + high) / 2;
    int a1Size = mid - low + 1;
    int a2Size = high - mid;

    vector<int> a1(a1Size);
    vector<int> a2(a2Size);

    for (int i = 0; i < a1Size; i++)
        a1[i] = a[low + i];
    for (int i = 0; i < a2Size; i++)
        a2[i] = a[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = low;

    // very Important note -> we have to check for the given condition before actually sorting the array

    while (i < a1Size && j < a2Size)
    {
        if (a1[i] > (long)2 * a2[j]) // long for a leetcode tc
        {
            count += a1Size - i;
            j++;
        }
        else
            i++;
    }

    i = j = 0;
    k = low;

    while (i < a1Size && j < a2Size)
    {
        if (a1[i] < a2[j])
            a[k] = a1[i++];
        else
            a[k] = a2[j++];
        k++;
    }

    while (i < a1Size)
        a[k++] = a1[i++];

    while (j < a2Size)
        a[k++] = a2[j++];

    return count;
}

int mergesort(vector<int> &a, int low, int high)
{
    int count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        count += mergesort(a, low, mid);
        count += mergesort(a, mid + 1, high);
        count += merge(a, low, high);
    }
    return count;
}
int reversePairs(vector<int> &nums)
{
    // reference ---> https://www.youtube.com/watch?v=PPOsH6NFNSE
    return mergesort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> v{2, 4, 3, 5, 1};
    cout << reversePairs(v) << endl;

    return 0;
}