#include <iostream>
using namespace std;

void subSequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    subSequence(input.substr(1), output);
    output += input[0];
    subSequence(input.substr(1), output);
}

int main()
{
    string s = "abcd";
    subSequence(s,"");

    return 0;
}