#include <iostream>
#include <vector>
using namespace std;

#define N 8

bool isSafe(int x, int y, vector<vector<int>> &sol)
{
    return (x >= 0 && y >= 0 && x < N && y < N && sol[x][y] == -1);
}

bool solveKTUtil(int x, int y, int movei, vector<vector<int>> &sol, int xMove[], int yMove[])
{
    if (movei == N * N)
        return true;
    for (int k = 0; k < 8; k++)
    {
        int next_x = x + xMove[k], next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove))
                return true;
            sol[next_x][next_y] = -1;
        }
    }
    return false;
}

void solveKT()
{
    vector<vector<int>> sol(N, vector<int>(N, -1));
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;
    if (!solveKTUtil(0, 0, 1, sol, xMove, yMove))
    {
        cout << "Solution does not exist." << endl;
        return;
    }

    for (auto row : sol)
    {
        for (auto cell : row)
            cout << cell << " ";
        cout << endl;
    }
}

int main()
{
    solveKT();
    return 0;
}
