#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/word-search-ii/

// The only purpose of using trie here is store the strings efficiently to check everytime if it's present or not, you can also use hashmap (but trie is more efficient)

class TrieNode
{
public:
    bool isWord;
    TrieNode *child[26];
    TrieNode()
    {
        isWord = false;

        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

void trieInsert(TrieNode *node, const string &word)
{
    for (const auto &ch : word)
    {
        if (node->child[ch - 'a'] == NULL)
            node->child[ch - 'a'] = new TrieNode();

        node = node->child[ch - 'a'];
    }
    node->isWord = true;
}

void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, string &word, vector<string> &result)
{
    if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] == '$' or node->child[board[i][j] - 'a'] == NULL)
        return;

    node = node->child[board[i][j] - 'a'];

    word.push_back(board[i][j]);

    if (node->isWord)
    {
        node->isWord = false;
        result.push_back(word);
    }

    char bak = board[i][j];
    board[i][j] = '$';

    dfs(board, i + 1, j, node, word, result);
    dfs(board, i - 1, j, node, word, result);
    dfs(board, i, j + 1, node, word, result);
    dfs(board, i, j - 1, node, word, result);

    word.pop_back();
    board[i][j] = bak;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    TrieNode *root = new TrieNode();
    vector<string> ans;
    string temp_word;

    for (const auto &i : words)
        trieInsert(root, i);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (root->child[board[i][j] - 'a'] != NULL)
            {
                dfs(board, i, j, root, temp_word, ans);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<char>> board{
        {'o', 'a', 'b', 'n'}, {'o', 't', 'a', 'e'}, {'a', 'h', 'k', 'r'}, {'a', 'f', 'l', 'v'}};

    vector<string> words{"oa", "oaa"};

    vector<string> ans = findWords(board, words);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}