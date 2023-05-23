#include <iostream>
#include <queue>
#include <vector>
#include <omp.h>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
void bfs(int start_node) 
{
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    while (!q.empty()) 
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        #pragma omp parallel for
        for (int i = 0; i < adj[u].size(); i++) 
        {
            int v = adj[u][i];
            if (!visited[v]) 
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int main() 
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    cout << "Enter the edges (u, v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
    int start_node;
    cout << "Enter the node to start BFS from: ";
    cin >> start_node;
    cout << "BFS traversal starting from node " << start_node << ": ";
    bfs(start_node);
    cout << endl;
    return 0;
}
