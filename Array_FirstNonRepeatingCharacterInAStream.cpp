#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

string FirstNonRepeating(string A)
{
    // reference --> https://www.youtube.com/watch?v=gbASJJAvAGk

    vector<int> vis(26, 0);
    vector<char> pos; // for storing what character came first

    string ans;

    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (!vis[A[i] - 'a'])
            pos.push_back(A[i]);

        vis[A[i] - 'a']++;

        int pos_array_size = pos.size();

        int j = 0;

        for (; j < pos_array_size; j++)
        {
            if (vis[pos[j] - 'a'] == 1)
            {
                ans.push_back(pos[j]);
                break;
            }
        }

        if (j == pos_array_size)
            ans.push_back('#');
    }

    return ans;
}