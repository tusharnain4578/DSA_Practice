#include <iostream>
#include <vector>
using namespace std;

class Trie
{
    struct Node
    {
        Node *links[26];
        bool end = false;

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

        void setEnd()
        {
            end = true;
        }

        bool isEnd()
        {
            return end;
        }
    };

    Node *root;

public:
    Trie() : root(new Node) {}

    void insert(string &word)
    {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            if (!temp->isContains(ch))
                temp->put(ch);

            temp = temp->get(ch);
        }
        temp->setEnd();
    }

    bool search(string word)
    {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            if (!temp->isContains(ch))
                return false;

            temp = temp->get(ch);
        }
        return temp->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *temp = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            char ch = prefix[i];

            if (!temp->isContains(ch))
                return false;

            temp = temp->get(ch);
        }
        return true;
    }
};

int main()
{
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            trie.insert(value[i]);
        }
        else if (type[i] == 2)
        {
            if (trie.search(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
        else
        {
            if (trie.startsWith(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
    }
}