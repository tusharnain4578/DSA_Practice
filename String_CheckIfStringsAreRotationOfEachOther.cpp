#include <iostream>
using namespace std;
// practice ---> https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

bool areRotations(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    s2 += s2; // concatenating s2 with s2, and then search for s1 in this, or you can go vice versa with s1 also

    if (s2.find(s1) == string::npos)
        return false;

    return true;
}