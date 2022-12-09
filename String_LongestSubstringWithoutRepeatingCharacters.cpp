#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    // reference ---> https://www.youtube.com/watch?v=qtVh-XEpsJo

    int len = 0;
    int left = 0, right = 0;

    unordered_map<char, int> mp;

    while (right < s.length())
    {
        if (mp.find(s[right]) != mp.end())
            left = max(left, mp[s[right]] + 1);

        mp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
int main()
{
    string str = "abcabcbb";
    cout << lengthOfLongestSubstring(str);
    return 0;
}