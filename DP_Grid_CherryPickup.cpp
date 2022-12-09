#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// practice --> https://leetcode.com/problems/cherry-pickup/

// Please revise in this order
// Recursion -> Memoization -> Tabulation -> Space Optimization

//
//
// in the below, approaches, the i1 + j1 will always be equals to i2 + j2 i.e, i1+j1 = i2+j2
// so instead of including j2 in our dp, we can calculate j2,  -->   j2 = i1 + j1 - i2;
//
// **IMPORTANT NOTE** -> You can't initialize dp matrix with -1 in memoized approach, because there's a chance that -1 can be stored in it, use INT_MIN instead, or you can also use -2
//
// Approaches ->

// Recursive Approach ------------------------------------------

int rec(vector<vector<int>> &grid, int i1, int j1, int i2)
{
    int j2 = i1 + j1 - i2; // first calculate j2

    if (i1 < 0 or i2 < 0 or j1 < 0 or j2 < 0 or grid[i1][j1] == -1 or grid[i2][j2] == -1)
        return -1;

    if (i1 == 0 and j1 == 0) // if 1st pointer reaches the destination, then the other will also reach, because the both have to travel same distance, same time
    {
        return grid[i1][j1];
    }

    int cherries = 0;

    int both_up = rec(grid, i1 - 1, j1, i2 - 1);
    int both_left = rec(grid, i1, j1 - 1, i2);
    int _one_up_one_left = rec(grid, i1 - 1, j1, i2);
    int _one_left_one_up = rec(grid, i1, j1 - 1, i2 - 1);

    int max_of_all = max(max(both_up, both_left), max(_one_up_one_left, _one_left_one_up));

    if (max_of_all == -1)
        return -1;

    cherries += max_of_all;

    // including current cherry or cherries
    if (i1 == i2 and j1 == j2)    // if both pointers are on same grid, include the cherry only once, if they're on different grids, then include both cherries
        cherries += grid[i1][j1]; // or grid[i2][j2] //they're same
    else
        cherries += grid[i1][j1] + grid[i2][j2];

    return cherries;
}

int cherryPickup_rec(vector<vector<int>> &grid)
{
    int n = grid.size();
    return max(0, rec(grid, n - 1, n - 1, n - 1)); // we are using max here because, if the path to destination is blocked and there's no way we can reach to destination, in that case, the rec function will return -1,
    // but the problem was stated to give 0
}

// Memoized Approach ------------------------------------------

int mem(vector<vector<int>> &grid, int i1, int j1, int i2, vector<vector<vector<int>>> &dp)
{
    int j2 = i1 + j1 - i2; // first calculate j2

    if (i1 < 0 or i2 < 0 or j1 < 0 or j2 < 0 or grid[i1][j1] == -1 or grid[i2][j2] == -1)
        return -1;

    if (i1 == 0 and j1 == 0) // if 1st pointer reaches the destination, then the other will also reach, because the both have to travel same distance, same time
    {
        return grid[i1][j1];
    }

    if (dp[i1][j1][i2] != INT_MIN) // checking for answer in dp
        return dp[i1][j1][i2];

    int cherries = 0;

    int both_up = mem(grid, i1 - 1, j1, i2 - 1, dp);
    int both_left = mem(grid, i1, j1 - 1, i2, dp);
    int _one_up_one_left = mem(grid, i1 - 1, j1, i2, dp);
    int _one_left_one_up = mem(grid, i1, j1 - 1, i2 - 1, dp);

    int max_of_all = max(max(both_up, both_left), max(_one_up_one_left, _one_left_one_up));

    if (max_of_all == -1)
        return dp[i1][j1][i2] = -1; // returning while storing in dp

    cherries += max_of_all;

    // including current cherry or cherries
    if (i1 == i2 and j1 == j2)    // if both pointers are on same grid, include the cherry only once, if they're on different grids, then include both cherries
        cherries += grid[i1][j1]; // or grid[i2][j2] //they're same
    else
        cherries += grid[i1][j1] + grid[i2][j2];

    return dp[i1][j1][i2] = cherries; // returning while storing in dp
}

int cherryPickup_mem(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN))); // 3d DP
    return max(0, mem(grid, n - 1, n - 1, n - 1, dp));
}

// Tabulated Approach ------------------------------------------

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    // we're initializing matrix of n+1, for 1 extra row to handle the base cases of out of bound indeces which returns -1, there are so many cases, that is why we are using extra size in dp
    // also we're initializing dp with -1, so the base cases are in the dp and we don't have to put -1 in some cases in the dp, because the -1 is already in that cell of dp
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1))); // 3d DP

    // when i1 == 0 and j1 == 0, then i2 and j2 will also be 0,
    // because i1 + j1 == i2 + j2
    // so according to the base case from the above recursive code, when i1 = 0 and j1 = 0, we return grid[0][0], when i1 = 0 , j1 = 0, then i2 will also be 0

    dp[1][1][1] = grid[0][0]; // we're using dp with block 1,1,1 because the 0,0,0 are for -1 out of bound base cases

    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                //-----------------
                const int j2 = i1 + j1 - i2;

                if (j2 < 1 or j2 > n) // i1, j1, and i2 are handled, but what if j2 is out of bound, we have to handle that case
                    continue;         // we're just continuing and not storing -1 in dp, because this location of dp already holds -1

                // the grid is measuring with minus 1 because the i1 j1 is 1 extra because of dp for loop
                if (grid[i1 - 1][j1 - 1] == -1 or grid[i2 - 1][j2 - 1] == -1) ////blockage/obstacle edge case
                    continue;

                int cherries = 0;

                int both_up = dp[i1 - 1][j1][i2 - 1];
                int both_left = dp[i1][j1 - 1][i2];
                int _one_up_one_left = dp[i1 - 1][j1][i2];
                int _one_left_one_up = dp[i1][j1 - 1][i2 - 1];

                int max_of_all = max(max(both_up, both_left), max(_one_up_one_left, _one_left_one_up));

                if (max_of_all == -1)
                    continue; // just continue, we don't have to do return dp[i1][j1][i2] = -1, because it is already -1 in dp

                cherries += max_of_all;

                // the grid is measuring with minus 1 because the i1 j1 is 1 extra because of dp for loop
                if (i1 == i2 and j1 == j2)
                    cherries += grid[i1 - 1][j1 - 1];
                else
                    cherries += grid[i1 - 1][j1 - 1] + grid[i2 - 1][j2 - 1];

                dp[i1][j1][i2] = cherries;
                //-----------------
            }
        }
    }
    return max(0, dp[n][n][n]);
}

// Space Optimization
//  This is a leetcode hard problem and it hogged my one and half of the day, made me sick and tired in understand the top-down and bottom-up approaches
//  i know it can be more optimized in terms of space, but look, it's a 3d array and at current mind state, i don't have that good understanding of 3d arrays
// And also it's fine if you don't space optimize it, becuse the bottom-up approach is more than enough