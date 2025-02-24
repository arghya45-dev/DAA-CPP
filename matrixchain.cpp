#include <iostream>
#include <climits>
using namespace std;

int matrixChainOrder(int p[], int n)
{
    int dp[n][n];
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications: " << matrixChainOrder(arr, n) << endl;
    return 0;
}
