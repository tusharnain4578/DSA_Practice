#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(const vector<int> &task, int mid, int days)
{
    int temp = 0;
    for (const int &i : task)
    {
        temp += i / mid;
        if ((i % mid && i > mid) || (i < mid))
            temp++;

        if (temp > days)
            return false;
    }

    return true;
}

int minimumWork(const vector<int> &task, int days)
{
    int low = 0, high = *max_element(task.begin(), task.end());

    int ans;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isValid(task, mid, days))
        {
            ans = mid;
            high = mid - 1;
            // cout << ans << endl;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> task{30, 20, 22, 4, 21};
    int days = 6;
    cout << minimumWork(task, days);

    return 0;
}