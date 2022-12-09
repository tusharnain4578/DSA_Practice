#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{

    vector<int> hash(26, 0);

    if (s.size() != t.size())
        return 0;

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }

    for (int t : hash)
    {
        if (t != 0)
            return 0;
    }

    return 1;
}

int main()
{
    string s = "anagram";
    string t = "margana";
    cout << isAnagram(s, t);

    return 0;
}