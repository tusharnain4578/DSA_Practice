#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/word-break1352/1

// reference --> https://www.youtube.com/watch?v=XtIGGdrF67E

// NOTE-> There is a trie solution for this which is faster and bettor than dp, you can find that in the Trie section of this folder

// recursion
bool rec(int i, string &s, int &n, unordered_set<string> &dictionary)
{
    if (i == n)
        return true;

    for (int j = i; j < n; j++)
    {
        string _this_string = s.substr(i, j - i + 1);

        if (dictionary.find(_this_string) != dictionary.end())
            if (rec(j + 1, s, n, dictionary))
                return true;
    }

    return false;
}

int wordBreak_rec(string A, vector<string> &B)
{
    unordered_set<string> dictionary(B.begin(), B.end()); // making kind of dictionary of words, because we have to look for the words many time, so for efficient approach we made a unordered set

    int str_size = A.size();
    int dictionary_size = B.size();

    return rec(0, A, str_size, dictionary);
}

// memoization
bool mem(int i, string &s, int &n, unordered_set<string> &dictionary, vector<int> &dp)
{
    if (i == n)
        return true;

    if (dp[i] != -1)
        return dp[i];

    for (int j = i; j < n; j++)
    {
        string _this_string = s.substr(i, j - i + 1);

        if (dictionary.find(_this_string) != dictionary.end())
            if (mem(j + 1, s, n, dictionary, dp))
                return dp[i] = true;
    }

    return dp[i] = false;
}

int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> dictionary(B.begin(), B.end());

    int str_size = A.size();
    int dictionary_size = B.size();

    vector<int> dp(str_size, -1); // cant make dp of bool, at least in memoization because we have to store -1 initially

    return mem(0, A, str_size, dictionary, dp);
}

// tabulation
int wordBreak(string A, vector<string> &B)
{
    unordered_set<string> dictionary(B.begin(), B.end());

    int str_size = A.size();
    int dictionary_size = B.size();

    vector<int> dp(str_size + 1, false);

    dp[str_size] = true; // base case

    for (int i = str_size - 1; i >= 0; i--)
    {
        bool flag = 0;

        for (int j = i; j < str_size; j++)
        {
            string _this_string = A.substr(i, j - i + 1);

            if (dictionary.find(_this_string) != dictionary.end())
                if (dp[j + 1])
                    dp[i] = true;
        }
    }

    return dp[0];
}

// cant optimize more, atleast in dp, idk about any other approach, i dont have to ig