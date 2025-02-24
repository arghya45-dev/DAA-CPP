#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(vector<vector<int>> &graph, int pos, int visited, vector<vector<int>> &dp)
{
    int n = graph.size();
    if (visited == (1 << n) - 1)
        return graph[pos][0]; // Return to start
    if (dp[pos][visited] != -1)
        return dp[pos][visited];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (!(visited & (1 << i)) && graph[pos][i] > 0)
        {
            int cost = graph[pos][i] + tsp(graph, i, visited | (1 << i), dp);
            ans = min(ans, cost);
        }
    }
    return dp[pos][visited] = ans;
}

int main()
{
    vector<vector<int>> graph = {{0, 10, 15, 20},
                                 {10, 0, 35, 25},
                                 {15, 35, 0, 30},
                                 {20, 25, 30, 0}};
    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    cout << "Minimum cost: " << tsp(graph, 0, 1, dp) << endl;
    return 0;
}
