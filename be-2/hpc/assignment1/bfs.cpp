#include <iostream>
#include <queue>
#include <vector>
#include <omp.h>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
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
        for (int i = 0; i < graph[u].size(); i++) 
        {
            int v = graph[u][i];
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
    int n, m, start_node;
    cout << "Enter no. of Node,no. of Edges and Starting Node of graph:\n";
    cin >> n >> m >> start_node;
    cout << "Enter the edges (u, v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        }
    bfs(start_node);
    cout << endl;
    return 0;
}
