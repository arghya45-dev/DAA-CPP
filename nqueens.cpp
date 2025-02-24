#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<int>> &board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". "; // Optional: use "." for empty cells
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>> &board, int col, int N)
{
    if (col >= N)
    {
        printSolution(board, N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1, N) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!solveNQueensUtil(board, 0, N))
        cout << "No solution exists!" << endl;
}

int main()
{
    int N = 4; // Change N as required
    solveNQueens(N);
    return 0;
}
