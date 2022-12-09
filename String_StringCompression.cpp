#include <iostream>
#include <vector>
using namespace std;
// practice ---> https://leetcode.com/problems/string-compression/

int compress(vector<char> &chars)
{
    int n = chars.size();

    int ansIndex = 0;

    int i = 0;

    while (i < n)
    {
        char currChar = chars[i];

        int count = 0;

        while (i < n and chars[i] == currChar)
        {
            i++;
            count++;
        }

        chars[ansIndex++] = currChar;

        if (count > 1)
        {
            string countStr = to_string(count);

            for (const auto ch : countStr)
                chars[ansIndex++] = ch;
        }
    }

    return ansIndex;
}