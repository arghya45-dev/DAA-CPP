#include <iostream>
#include <vector>
using namespace std;

double fractionalKnapsack(int W, vector<pair<int, int>> &items)
{
    int n = items.size();
    vector<vector<double>> dp(n + 1, vector<double>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (items[i - 1].second <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].second] + items[i - 1].first);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main()
{
    vector<pair<int, int>> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << "Maximum value: " << fractionalKnapsack(W, items) << endl;
    return 0;
}
