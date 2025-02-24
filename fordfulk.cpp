#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

bool bfs(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent)
{
    int n = rGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>> &graph, int s, int t)
{
    int n = graph.size();
    vector<vector<int>> rGraph = graph;
    vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent))
    {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main()
{
    vector<vector<int>> graph = {{0, 16, 13, 0, 0, 0},
                                 {0, 0, 10, 12, 0, 0},
                                 {0, 4, 0, 0, 14, 0},
                                 {0, 0, 9, 0, 0, 20},
                                 {0, 0, 0, 7, 0, 4},
                                 {0, 0, 0, 0, 0, 0}};
    cout << "Maximum flow: " << fordFulkerson(graph, 0, 5) << endl;
    return 0;
}
