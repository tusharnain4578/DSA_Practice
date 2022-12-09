#include <iostream>
using namespace std;
// practice ---> https://leetcode.com/problems/reverse-vowels-of-a-string/

bool isVowel(const char &ch)
{
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U';
}

string reverseVowels(string s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        while (!isVowel(s[i]) and i < j)
            i++;

        while (!isVowel(s[j]) and i < j)
            j--;

        if (i < j)
            swap(s[i++], s[j--]);
    }

    return s;
}

int main()
{
    string s = "hello";
    string str = "aeiou";

    string ans = reverseVowels(str);

    cout << ans << endl;

    return 0;
}