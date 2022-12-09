#include <iostream>
#include <vector>
#include <map>
using namespace std;
// practice ---> https://leetcode.com/problems/image-overlap/

// reference --> https://www.youtube.com/watch?v=gl57zvHrgrQ

int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
    int n = img1.size(); // img1 and img2 sizes are same

    vector<pair<int, int>> non_zero1, non_zero2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (img1[i][j] == 1)
                non_zero1.push_back(make_pair(i, j));

            if (img2[i][j] == 1)
                non_zero2.push_back(make_pair(i, j));
        }
    }

    // we cannot create an unordered map with a pair as a key, that's why using map instead
    map<pair<int, int>, int> mp;

    int ans = 0;

    for (auto const [i1, j1] : non_zero1)
    {
        for (auto const [i2, j2] : non_zero2)
        {
            mp[make_pair(i2 - i1, j2 - j1)]++;

            ans = max(ans, mp[make_pair(i2 - i1, j2 - j1)]);
        }
    }

    return ans;
}