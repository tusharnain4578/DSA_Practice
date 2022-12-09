#include <iostream>
#include <vector>
using namespace std;

//****
// Note >>>>> There are two approaches, first is to accumulate sum and compare with the k, or reduce the k to 0, code for both approaches are mentioned below, recommended is the one which reduces the k
//***
void subsequenceSum(vector<int> &input, int k, int index, vector<int> &output, int sum)
{
    if (index == input.size())
    {
        if (sum == k)
        {
            for (auto it : output)
                cout << it << " ";

            cout << endl;
        }
        return;
    }
    subsequenceSum(input, k, index + 1, output, sum);

    sum += input[index];

    output.push_back(input[index]);

    subsequenceSum(input, k, index + 1, output, sum);

    output.pop_back();
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, -3};
    int k = 3;
    vector<int> output;
    subsequenceSum(a, k, 0, output, 0);

    return 0;
}

// In the below code, everything is same, i just reduced the k variable and when it becomes zero, i print it

// #include <iostream>
// #include <vector>
// using namespace std;

// void subsequenceSum(vector<int> &input, int k, vector<int> output = {}, int index = 0)
// {
//     if (index == input.size())
//     {
//         if (!k)
//         {
//             for (auto it : output)
//                 cout << it << " ";

//             cout << endl;
//         }
//         return;
//     }
//     subsequenceSum(input, k, output, index + 1);
//     output.push_back(input[index]);
//     subsequenceSum(input, k - input[index], output, index + 1);
// }

// int main()
// {
//     vector<int> a{1, 2, 3, 4, 5, 6, -3};
//     vector<int> temp;
//     subsequenceSum(a, 3);

//     return 0;
// }