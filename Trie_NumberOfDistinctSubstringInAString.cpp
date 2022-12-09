#include <iostream>
using namespace std;

struct Node
{
    Node *links[26];

    bool isContains(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch)
    {
        links[ch - 'a'] = new Node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
    Node *root;

public:
    Trie() : root(new Node) {}
    int insert(string word)
    {
        Node *temp = root;
        int ct = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->isContains(word[i]))
            {
                temp->put(word[i]);
                ct++;
            }
            temp = temp->get(word[i]);
        }
        return ct;
    }
};

int countDistinctSubstrings(string &s)
{
    int ans = 0;
    Trie *t = new Trie;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            ans += t->insert(s.substr(i, j + 1));
        }
    }
    return ans + 1; //+1 for empty substring
}

int main()
{
    string s = "abab";
    cout << countDistinctSubstrings(s);
    return 0;
}