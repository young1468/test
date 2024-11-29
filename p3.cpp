#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isBipart(int n, vector<vector<int>> graph, vector<int> &set1, vector<int> &set2)
{
    vector<int> color(n + 1, -1);
    queue<int>q;
    q.push(1);
    color[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int neighbor : graph[cur])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[cur];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[cur])
            {
                return false;
            }
        }
    }
    for (int i = 1; i < n + 1; ++i)
    {
        if (color[i] == 0)
        {
            set1.push_back(i);
        }
        else
        {
            set2.push_back(i);
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> set1;
    vector<int> set2;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (isBipart(n, graph, set1, set2))
    {
        cout << "YES" << endl;
        for (int x : set1)
        {
            if (x == set1[0])
            {
                cout << x;
            }
            else
            {
                cout << " " << x;
            }
        }
        cout << endl;
        for (int x : set2)
        {
            if (x == set2[0])
            {
                cout << x;
            }
            else
            {
                cout << " " << x;
            }
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}