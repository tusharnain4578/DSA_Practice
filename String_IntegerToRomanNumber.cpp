#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/integer-to-roman/

string intToRoman(int num)
{
    // reference ---> https://www.youtube.com/watch?v=zNlm28-ZdaE

    vector<string> roman{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans = "";

    // 13 is vector's size
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += roman[i];
            num -= values[i];
        }
    }
    return ans;
}

int main()
{
    int num = 1948;
    cout << intToRoman(num) << endl;
    return 0;
}