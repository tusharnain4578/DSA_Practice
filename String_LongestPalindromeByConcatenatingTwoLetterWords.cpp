#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// practice ---> https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

// reference --> https://www.youtube.com/watch?v=HmEqS_aYt40

int longestPalindrome(vector<string> &words)
{
    map<string, int> mp;

    int ans = 0, palin_word_len = 0;
    bool flag = false;

    for (auto const &str : words)
        mp[str]++;

    for (auto const &x : mp)
    {
        if (x.first[0] == x.first[1])
        {
            if (x.second % 2 == 0)
                palin_word_len += x.second * 2;
            else
            {
                flag = true;
                palin_word_len += (x.second - 1) * 2;
            }

            mp[x.first] = 0;
        }
        else
        {
            string temp = x.first;
            reverse(temp.begin(), temp.end());

            if (mp.find(temp) != mp.end())
                ans += min(mp[temp], x.second) * 4;

            mp[temp] = 0;
            mp[x.first] = 0;
        }
    }

    if (flag)
        return ans + palin_word_len + 2;

    return ans + palin_word_len;
}

int main()
{
    // vector<string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};
    vector<string> words = {"lc", "cl", "gg"};
    int ans = longestPalindrome(words);

    cout << ans << endl;

    return 0;
}