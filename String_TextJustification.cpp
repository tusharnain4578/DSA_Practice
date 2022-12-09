#include <iostream>
#include <vector>
using namespace std;
// practice --> https://leetcode.com/problems/text-justification/
// Leetcode HARD

string left_justify(const vector<string> &words, int total_spaces, int i, int j)
{
    string res = words[i]; // initializing res, with atleast 1st word

    int spaces_on_right = total_spaces - (j - i - 1);

    for (int k = i + 1; k < j; k++)
        res.append(" " + words[k]);

    while (spaces_on_right--) // appending rightmost spaces
        res.append(" ");

    return res;
}

string middle_justify(const vector<string> &words, int total_spaces, int i, int j)
{
    string res = words[i];

    int space_needed = j - i - 1;                   // the single spaces word's have
    int space = total_spaces / space_needed;        // the division of total spaces
    int extra_spaces = total_spaces % space_needed; // extra spaces (needed for leftmost words)

    for (int k = i + 1; k < j; k++)
    {
        int space_to_apply = space + (extra_spaces-- > 0 ? 1 : 0);
        while (space_to_apply--)
            res.append(" ");

        res.append(words[k]);
    }

    return res;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    // reference ---> https://www.youtube.com/watch?v=GqXlEbFVTXY

    int n = words.size(), i = 0;
    vector<string> result;

    while (i < n)
    {
        int j = i + 1;
        int lineLength = words[i].length();

        while (j < n and (lineLength + words[j].length() + j - i - 1 < maxWidth)) // j - i - 1 => spaces (single)
        {
            lineLength += words[j].length();
            j++;
        }

        int total_spaces = maxWidth - lineLength;
        int total_words = j - i; // total words in the line

        if (total_words == 1 or j == n) // if word is single in a line or it' the list line, we'll do left justification
            result.push_back(left_justify(words, total_spaces, i, j));
        else
            result.push_back(middle_justify(words, total_spaces, i, j));

        i = j;
    }

    return result;
}