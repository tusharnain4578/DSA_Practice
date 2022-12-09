#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &stalls, int k, int mid)
{
    int cows_count = 1;
    int last_placed_count = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last_placed_count >= mid)
        {
            last_placed_count = stalls[i];
            cows_count++;
            if (cows_count == k)
                return true;
        }
    }
    if (cows_count >= k)
        return true;

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    // reference ----> https://youtu.be/YTTdLgyqOLY?t=2619

    sort(stalls.begin(), stalls.end());

    int low = 0, high = stalls[stalls.size() - 1];

    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isValid(stalls, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> stalls{4, 2, 1, 3, 6};
    int k = 2;

    cout << aggressiveCows(stalls, k);
    return 0;
}