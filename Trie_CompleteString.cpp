#include <iostream>
#include <vector>
using namespace std;

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

class Trie
{
    Node *root;

public:
    Trie() : root(new Node) {}

    void insert(string word)
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

    bool checkIfAllPrefixExists(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (temp->isContains(ch) && temp->get(ch)->isEnd())
                temp = temp->get(ch);
            else
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie *t = new Trie;
    string largest = "";
    for (string &i : a)
        t->insert(i);

    for (string &i : a)
    {
        if (t->checkIfAllPrefixExists(i))
        {
            if (i.size() > largest.size())
                largest = i;
            else if (i.size() == largest.size() && i < largest)
                largest = i;
        }
    }
    if (largest == "")
        return "None";

    return largest;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<string> v;
        string x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        x = completeString(n, v);
        cout << endl
             << x << "---" << endl;
    }
    return 0;
}