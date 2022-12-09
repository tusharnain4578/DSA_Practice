#include <iostream>
#include <unordered_map>
using namespace std;

int romanToDecimal(string &str)
{
    // reference ---> https://www.youtube.com/watch?v=XEDmWJ3PMTY

    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int n = str.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 and m[str[i]] < m[str[i + 1]])
        {
            ans += m[str[i + 1]] - m[str[i]];
            i++; // extra increment coz we have covered two characters in this case
        }
        else
            ans += m[str[i]];
    }
    return ans;
}