
#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{

    list<int> queue;

    bool visited[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

int printShortestDistance(vector<int> adj[], int s,
                          int dest, int v)
{
    int pred[v], dist[v];

    if (BFS(adj, s, dest, v, pred, dist) == false)
    {
        return -1;
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    return dist[dest];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, blackVertex;
        cin >> n >> blackVertex;
        int arr[n];
        for (int i = 0; i < n - 1; i++)
        {
            int x;
            cin >> x;
            arr[i] = x - 1;
        }

        vector<int> edges[n + 1];
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            add_edge(edges, u - 1, v - 1);
        }

        int mini = INT_MAX;
        vector<int> blackVertices;
        blackVertices.push_back(blackVertex - 1);
        for (int i = 0; i < n - 1; i++)
        {
            if(mini == 1)
            {
                cout << mini << " ";
                continue;
            }
            for (int j = 0; j < blackVertices.size(); j++)
            {
                if (mini == 1)
                {
                    break;
                }
                mini = min(mini, printShortestDistance(edges, blackVertices[j], arr[i], n));
            }
            cout << mini << " ";
            blackVertices.push_back(arr[i]);
        }
        cout << "\n";
    }
    return 0;
}