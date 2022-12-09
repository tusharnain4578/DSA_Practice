#include <iostream>
#include <unordered_map>
using namespace std;
// practice -->- https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

char nonrepeatingCharacter(string S)
{
    unordered_map<char, int> mp;

    for (const char &i : S)
        mp[i]++;

    for (const char &i : S)
        if (mp[i] == 1)
            return i;

    return '$';
}