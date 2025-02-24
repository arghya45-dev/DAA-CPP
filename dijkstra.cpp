#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Include this for INT_MAX
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int src)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // Use INT_MAX from <climits>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : graph[u])
        {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Distance to node " << i << ": " << dist[i] << endl;
}

int main()
{
    vector<vector<pair<int, int>>> graph = {{{1, 2}, {2, 4}},
                                            {{0, 2}, {2, 1}, {3, 7}},
                                            {{0, 4}, {1, 1}, {3, 3}},
                                            {{1, 7}, {2, 3}}};
    dijkstra(graph, 0);
    return 0;
}
