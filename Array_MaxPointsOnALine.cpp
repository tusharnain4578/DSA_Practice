#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/max-points-on-a-line/

int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();

    if (points.size() <= 2)
        return points.size();

    int maxPoints = 0;

    for (int i = 0; i < n; i++)
    {
        // line's 1st coordinate
        int &x1 = points[i][0];
        int &y1 = points[i][1];

        for (int j = i + 1; j < n; j++)
        {
            // line's 2nd coordinate
            int &x2 = points[j][0];
            int &y2 = points[j][1];

            int total_points = 2; // line weill have two points initially

            // looping the middle points in line

            for (int k = 0; k < n; k++)
            {
                if (k != i and k != j)
                {
                    // line's middle points'coordinate
                    int &x3 = points[k][0];
                    int &y3 = points[k][1];

                    if ((x2 - x3) * (y3 - y1) == (x3 - x1) * (y2 - y3))
                        total_points++;
                }
            }

            maxPoints = max(maxPoints, total_points);
        }
    }

    return maxPoints;
}