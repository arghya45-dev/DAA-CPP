#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(vector<Edge> &edges, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (auto &edge : edges)
        {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest])
            {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    for (auto &edge : edges)
    {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest])
        {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << "Distance from source to vertex " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    int V = 5;
    vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    bellmanFord(edges, V, 0);
    return 0;
}
