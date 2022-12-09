#include <iostream>
using namespace std;
// Leetcode link ---> https://leetcode.com/problems/reverse-words-in-a-string-iii/

void reverse(string &s, int i, int j)
{
    while (i < j)
        swap(s[i++], s[j--]);
}

string reverseWords(string s)
{
    int i = 0, j = 0;
    int n = s.size();

    while (j < n)
    {
        if (s[j] == ' ')
        {
            reverse(s, i, j - 1);
            i = j + 1;
        }

        j++;
    }

    reverse(s, i, j - 1);

    return s;
}

int main()
{
    string s = "This is awesome";
    cout << reverseWords(s);

    return 0;
}