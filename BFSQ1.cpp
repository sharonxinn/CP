//A. Bear and Friendship Condition

// For every three distinct members (X, Y, Z), if X-Y and Y-Z then also X-Z.
// if Alan and Bob are friends, and Bob and Ciri are friends, then Alan and Ciri should be friends as well.


//Input: n: number of members (nodes)
//m: number of friendships (edges)
//ai bi: friendship between ai and bi

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 150005;

vector<int> adj[MAXN];  // [A] Adjacency list to store friendships
bool visited[MAXN];     // [B] Visited array to mark visited nodes

int main() {
    int n, m;
    cin >> n >> m;

    // [C] Build the graph: Read friendships and fill adjacency list  //$$
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // [D] Traverse each connected component using BFS
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int nodeCount = 0;         // Count of nodes in the component
            long long edgeCount = 0;   // Count of edges in the component

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                nodeCount++;
                edgeCount += adj[node].size(); // Count edges from this node

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            // [E] Each edge is counted twice in an undirected graph
            edgeCount /= 2;

            // [F] For a component to be a clique:
            long long expectedEdges = 1LL * nodeCount * (nodeCount - 1) / 2;
            if (edgeCount != expectedEdges) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    // [G] All components passed the clique check
    cout << "YES" << endl;
    return 0;
}

