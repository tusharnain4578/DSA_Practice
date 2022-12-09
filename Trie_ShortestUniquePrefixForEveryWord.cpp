#include <iostream>
#include <vector>
using namespace std;
// Practice ---> https://practice.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1/

// GFG Hard
// Did it on my own, in the first attempt, without any article or video 😁

// TrieNode

class TrieNode
{
public:
    TrieNode *child[26];
    int wordCount;
    bool isEnd;

    TrieNode() : wordCount(0), isEnd(false)
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

        curr->child[ch - 'a']->wordCount++;

        curr = curr->child[ch - 'a'];
    }

    curr->isEnd = true;
}

string getUniquePrefixFromTrie(TrieNode *root, const string &str)
{
    TrieNode *curr = root;

    string unique = "";

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        unique += ch;

        if (curr->child[ch - 'a']->wordCount == 1)
            break;

        curr = curr->child[ch - 'a'];
    }

    return unique;
}

vector<string> findPrefixes(string arr[], int n)
{
    TrieNode *root = new TrieNode;

    vector<string> ans;

    for (int i = 0; i < n; i++)
        insertWord(root, arr[i]);

    for (int i = 0; i < n; i++)
        ans.push_back(getUniquePrefixFromTrie(root, arr[i]));

    return ans;
}

int main()
{
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<string> ans = findPrefixes(arr, n);

    for (auto const &str : ans)
        cout << str << " ";

    return 0;
}