#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1/

// aaaahhhhhhh -> this one's hard, and a bummer

pair<int, int> largestSubarrayWith0Sum(vector<int> const &arr)
{
    int n = arr.size();

    pair<int, int> indeces{-1, -1};
    int maxLen = 0;

    unordered_map<int, int> mp;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            if (i - 0 + 1 > maxLen)
            {
                indeces = {0, i};
                maxLen = i - 0 + 1;
            }
        }
        else if (mp.count(sum))
        {
            if (i - mp[sum] > maxLen)
            {
                indeces = {mp[sum] + 1, i};
                maxLen = i - mp[sum];
            }
        }
        else
        {
            mp[sum] = i;
        }
    }
    return indeces;
}

vector<vector<int>> sumZeroMatrix(vector<vector<int>> arr)
{
    int m = arr.size(), n = arr[0].size();

    int maxArea = 0;

    int starting_row = -1, starting_col = -1, ending_row = -1, ending_col = -1;

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);

        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp[k] += arr[j][k];
            }

            pair<int, int> p = largestSubarrayWith0Sum(temp);

            if (p.first != -1)
            {
                int length = j - i + 1;
                int width = p.second - p.first + 1;

                int this_area = length * width;

                if ((this_area > maxArea) or
                    ((this_area == maxArea) and (p.first < starting_col)) or
                    ((this_area == maxArea) and (p.first == starting_col) and (i < starting_row)))
                {
                    maxArea = length * width;

                    starting_row = i;
                    ending_row = j;
                    starting_col = p.first;
                    ending_col = p.second;
                }
            }
        }
    }

    if (starting_row == -1)
        return {{-1}};

    vector<vector<int>> ans;

    for (int i = starting_row; i <= ending_row; i++)
    {
        vector<int> temp;
        for (int j = starting_col; j <= ending_col; j++)
            temp.push_back(arr[i][j]);
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    vector<vector<int>> ans = sumZeroMatrix(arr);

    cout << "-----------" << endl;
    for (const auto &i : ans)
    {
        for (const auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}