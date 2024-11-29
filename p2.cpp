#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> inDegree(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    queue<int> q;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }
    for(int i = 1; i < n+1; ++i){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    int visited=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        visited++;
        for(int neighbor: graph[cur]){
            inDegree[neighbor]--;
            if(inDegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    if(visited!=n){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}