#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1/

// TrieNode

// Although there's a dp solution, but this Trie solution is faster

class TrieNode
{
public:
    TrieNode *child[26];

    bool isEnd;

    TrieNode() : isEnd(false)
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

void insertWord(TrieNode *root, const string &str)
{
    TrieNode *curr = root;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (curr->child[ch - 'a'] == NULL)
            curr->child[ch - 'a'] = new TrieNode();

        curr = curr->child[ch - 'a'];
    }

    curr->isEnd = true;
}

// searching word in trie
bool searchWord(TrieNode *root, const string &str)
{
    TrieNode *curr = root;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (curr->child[ch - 'a'] == NULL)
            return false;

        curr = curr->child[ch - 'a'];
    }

    return curr->isEnd;
}

// searching if string A is in dictionary/trie
bool findWord(int i, const string &str, const int &n, TrieNode *&root, vector<int> &dp)
{
    if (i == n)
        return true;

    if (dp[i] != -1)
        return dp[i];

    for (int j = i; j < n; j++)
    {
        string _this_string = str.substr(i, j - i + 1);

        if (searchWord(root, _this_string))
            if (findWord(j + 1, str, n, root, dp))
                return dp[i] = true;
    }

    return dp[i] = false;
}

int wordBreak(string A, vector<string> &B)
{
    TrieNode *root = new TrieNode;

    vector<int> dp(A.size(), -1);

    for (const string &str : B)
        insertWord(root, str);

    return findWord(0, A, A.size(), root, dp);
}