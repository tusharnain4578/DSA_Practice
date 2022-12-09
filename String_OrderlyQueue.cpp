#include <iostream>
#include <algorithm>
using namespace std;
// practice ---> https://leetcode.com/problems/orderly-queue/

// reference --> https://www.youtube.com/watch?v=ff8kxXeFhl8

string orderlyQueue(string s, int k)
{
    if (k <= 1)
    {
        int n = s.size();

        string ss = s + s;
        int ss_size = ss.size();

        string ans = s;

        for (int i = 1; i < n; i++)
        {
            string ss_sub = ss.substr(i, n);

            if (ss_sub < ans)
                ans = ss_sub;
        }

        return ans;
    }

    sort(s.begin(), s.end());

    return s;
}