#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
// practice ---> https://leetcode.com/problems/minimum-genetic-mutation/

// BFS

// reference ---> https://www.youtube.com/watch?v=_uH8GJPOKXI

int minMutation(string start, string end, vector<string> &bank)
{
    int n = start.size(); // start and end are of same size

    unordered_set<string> visited;

    queue<string> q;

    q.push(start);

    int ans_moves = 0;

    while (!q.empty())
    {
        int q_size = q.size();

        while (q_size--)
        {
            string node = q.front();
            q.pop();

            if (node == end)
                return ans_moves;

            for (int j = 0; j < n; j++)
            {
                for (char gene_chars : "ACGT")
                {
                    string temp_node = node;

                    temp_node[j] = gene_chars;

                    if (!visited.count(temp_node) and find(bank.begin(), bank.end(), temp_node) != bank.end())
                    {
                        q.push(temp_node);
                        visited.insert(temp_node);
                    }
                }
            }
        }

        ans_moves++;
    }
    return -1;
}