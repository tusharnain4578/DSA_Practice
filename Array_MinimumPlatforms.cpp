#include <iostream>
#include <algorithm>
using namespace std;

// practice --> https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/
int findPlatform(int arr[], int dep[], int n)
{
    // reference --> https://www.youtube.com/watch?v=dxVcMDI7vyI
    // another reference ---> https://www.youtube.com/watch?v=FkJZlZHWUyk
    // highly highly highly recommended
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 0; // iterator for arr
    int j = 0; // iterator for dep

    int platform = 0;
    int max_platforms = 0;

    while (i < n and j < n)
    {
        if (arr[i] <= dep[j]) // <= is important
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        max_platforms = max(max_platforms, platform);
    }

    return max_platforms;
}
int main()
{
    // both array sizes are supposed to be same
    int arr[]{900, 940, 950, 1100, 1500, 1800};
    int dep[]{910, 1200, 1120, 1130, 1900, 2000};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << findPlatform(arr, dep, size);

    return 0;
}