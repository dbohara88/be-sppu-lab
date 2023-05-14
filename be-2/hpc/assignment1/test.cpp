#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

// Function to perform BFS traversal
void BFS(vector<int> adj[], int start, bool visited[]) {
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    // Iterate until queue is empty
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int u = q.front();
        cout << u << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex u
        #pragma omp parallel for
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            // If adjacent vertex v is not visited, mark it visited and enqueue it
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Create an adjacency list to represent the graph
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Mark all vertices as not visited
    bool visited[n + 1] = {false};

    // Perform BFS traversal starting from vertex 1
    BFS(adj, 1, visited);

    return 0;
}
