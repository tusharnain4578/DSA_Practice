#include <iostream>
using namespace std;
void permute(string &input, int index = 0)
{
    if (index == input.length())
    {
        cout << input << endl;
        return;
    }
    for (int i = index; i < input.length(); i++)
    {
        swap(input[i], input[index]);
        permute(input, index + 1);
        swap(input[i], input[index]);
    }
}
int main()
{
    string s = "123";
    // string s2 = "0001";
    permute(s);
    // permute(s2);
    return 0;
}