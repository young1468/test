#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(n + 1, -2);
    vector<vector<int>> graph(n + 1);
    queue<int> q;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int neighbor : graph[cur])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[cur] + 1;
                q.push(neighbor);
            }
        }
    }
    for (int i = 2; i < n + 1; ++i)
    {
        if (i == 2)
            cout << dist[i];
        else
            cout << " " << dist[i];
    }
    return 0;
}