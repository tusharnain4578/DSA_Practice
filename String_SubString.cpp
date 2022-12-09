#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        string res;
        for (int j = i; j < s.length(); j++)
        {
            res += s[j];
            cout << res << endl;
        }
    }

    return 0;
}