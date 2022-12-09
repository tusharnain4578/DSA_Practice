#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

// reference -> Longest Palindromic substring in String Section
// There is a DP way, but this approach is way faster

int countSubstrings(string s)
{
    int n = s.size();

    int low, high;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        // even case
        low = i, high = i + 1;

        while (low >= 0 and high < n and s[low] == s[high])
        {
            count++;
            low--;
            high++;
        }

        // odd case
        low = i;
        high = i;

        while (low >= 0 and high < n and s[low] == s[high])
        {
            count++;
            low--;
            high++;
        }
    }

    return count;
}