#include <iostream>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.length();
    int m = needle.length();
    if (!m)
        return 0;

    for (int i = 0; i <= n-m; i++)
    {
        if (haystack[i] == needle[0] && haystack.substr(i, m) == needle)
            return i;
    }
    return -1;
}

int main()
{
    string a = "aaa";
    string b = "aa";
    cout << strStr(a, b);

    return 0;
}