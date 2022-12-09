#include <iostream>
using namespace std;
void printBoard(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int **board, int n, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool nqueens(int **board, int row, int n)
{
    if (row >= n) // Base Case
    {
        printBoard(board, n);
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, n, row, col))
        {
            // Placing Queen
            board[row][col] = 1;

            // Solving next subproblem
            if (nqueens(board, row + 1, n))
                return true;

            // Backtracking   //Removing the Queen
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n = 5;
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }
    nqueens(board, 0, n);

    return 0;
}

// The other way around ---->

// #include <iostream>
// using namespace std;

// bool isSafe(bool **board, int row, int col, int n)
// {
//     int i, j;
//     for (i = 0; i < col; i++)
//         if (board[row][i])
//             return false;

//     for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
//         if (board[i][j])
//             return false;

//     for (i = row, j = col; i < n && j >= 0; i++, j--)
//         if (board[i][j])
//             return false;

//     return true;
// }

// void printBoard(bool **board, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             cout << board[i][j] << " ";
//         cout << endl;
//     }
// }

// bool nqueens(bool **board, int col, int n)
// {
//     if (col >= n)
//     {
//         printBoard(board, n);
//         return true;
//     }

//     for (int row = 0; row < n; row++)
//     {
//         if (isSafe(board, row, col, n))
//         {
//             board[row][col] = true;

//             if (nqueens(board, col + 1, n))
//                 return true;

//             board[row][col] = false;
//         }
//     }
//     return false;
// }

// int main()
// {
//     int n = 5;
//     bool **board = new bool *[n];

//     for (int i = 0; i < n; i++)
//     {
//         board[i] = new bool[n];
//         for (int j = 0; j < n; j++)
//             board[i][j] = false;
//     }
//     nqueens(board, 0, n);

//     // printBoard(board, n);

//     return 0;
// }