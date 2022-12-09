#include <iostream>
using namespace std;

void powerSet(const string &str, int index, string &output)
{
    if (index == str.size())
    {
        cout << output << endl;
        return;
    }
    output.push_back(str[index]);
    powerSet(str, index + 1, output);
    output.pop_back();
    powerSet(str, index + 1, output);
}

int main()
{
    string s = "abc";
    string output;
    powerSet(s, 0, output);
    return 0;
}