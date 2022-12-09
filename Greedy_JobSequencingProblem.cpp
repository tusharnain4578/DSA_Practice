#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    // reference ---> https://www.youtube.com/watch?v=LjPx4wQaRIs
    sort(arr, arr + n, comp);

    int max_deadline = arr[0].dead;

    for (int i = 1; i < n; i++)
        max_deadline = max(arr[i].dead, max_deadline);

    int deadline_slot[max_deadline];
    memset(deadline_slot, -1, sizeof(deadline_slot));

    int job_count = 0, job_profit = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (deadline_slot[j - 1] == -1)
            {
                deadline_slot[j - 1] = arr[i].id;
                job_count++;
                job_profit += arr[i].profit;
                break;
            }
        }
    }
    ans.push_back(job_count);
    ans.push_back(job_profit);
    return ans;
}

int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }

        // function call
        vector<int> ans = JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}