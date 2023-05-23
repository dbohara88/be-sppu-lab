#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>

using namespace std;

const int MAX = 100000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) 
{
	stack<int> s;
	s.push(node);

	while (!s.empty()) 
    {
    	int u = s.top();

    	if (!visited[u]) 
        {
        	visited[u] = true;
            s.pop();
            cout<<u<<" ";
        	#pragma omp parallel for
        	for (int i = 0; i < graph[u].size(); i++) 
            {
            	int v = graph[u][i];
            	if (!visited[v]) {
                	s.push(v);
            	}
        	}
    	}
	}
}

int main() {
	int n, m, start_node;
	cout<<"Enter no. of Node,no. of Edges and Starting Node of graph:\n";
	cin >> n >> m >> start_node;
         //n: node,m:edges
    cout<<"Enter the edges (u, v):\n";

	for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
//u and v: Pair of edges
    	graph[u].push_back(v);
    	graph[v].push_back(u);
	}

	#pragma omp parallel for
	for (int i = 0; i < n; i++) {
    	visited[i] = false;
	}

	dfs(start_node);

	

	return 0;
}

/*output
Enter no. of Node,no. of Edges and Starting Node of graph:
4 3 0
Enter pair of node and edges:
0 1
0 2
2 4
0 2 4 1 
*/
