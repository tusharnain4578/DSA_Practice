#include <iostream>
using namespace std;

struct Node
{
    Node *links[26];
    int prefix_count = 0;
    int end_count = 0;

    void put(char ch)
    {
        links[ch - 'a'] = new Node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    bool isContains(char ch)
    {
        return links[ch - 'a'];
    }
    void incrementEnd()
    {
        end_count++;
    }
    void incrementPrefix()
    {
        prefix_count++;
    }
    int getEnd()
    {
        return end_count;
    }
    int getPrefexCount()
    {
        return prefix_count;
    }
    void deleteEnd()
    {
        end_count--;
    }
    void reducePrefixCount()
    {
        prefix_count--;
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
            temp->incrementPrefix();
        }
        temp->incrementEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (!temp->isContains(ch))
                return 0;

            temp = temp->get(ch);
        }
        return temp->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            if (!temp->isContains(ch))
                return 0;

            temp = temp->get(ch);
        }
        return temp->getPrefexCount();
    }

    void erase(string &word)
    {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            if (!temp->isContains(ch))
                return;

            temp = temp->get(ch);
            temp->reducePrefixCount();
        }
        temp->deleteEnd();
    }
};

int main()
{
    Trie T;
    T.insert("apple");
    T.insert("apple");
    T.insert("apps");
    T.insert("apps");
    string word1 = "apps";
    cout << "Count Words Equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
    string word2 = "abc";
    cout << "Count Words Equal to " << word2 << " " << T.countWordsEqualTo(word2) << endl;
    string word3 = "ap";
    cout << "Count Words Starting With " << word3 << " " << T.countWordsStartingWith(word3)
         << endl;
    string word4 = "appl";
    cout << "Count Words Starting With " << word4 << " " << T.countWordsStartingWith(word4)
         << endl;
    T.erase(word1);
    cout << "Count Words equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
    return 0;
}