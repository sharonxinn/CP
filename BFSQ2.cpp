//first line denotesnumber of nodes in tree
//n-1 line describe the edges of tree
//each line contains x and y(1<x,y<n)(ndpoints of the corresponding edge of the tree)
//last line contains n distinct integers (sequence to check)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    // [A] Build adjacency list
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {  //$$
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // [B] Read BFS sequence to verify
    vector<int> seq(n);
    for (int i = 0; i < n; ++i)
        cin >> seq[i];

    // [C] Check that the sequence starts with vertex 1
    if (seq[0] != 1) {
        cout << "No\n";
        return 0;
    }

    // [D] Initialize visited array and queue for BFS
    vector<bool> visited(n + 1, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);

    int idx = 1; // index in `seq` we are validating next

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // [E] Collect unvisited neighbors of current node (BFS Layer)
        unordered_set<int> expected_children;
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor])
                expected_children.insert(neighbor);
        }

        int count = expected_children.size();

        // [F] Check next `count` elements in sequence match these children
        for (int i = 0; i < count; ++i) {
            if (idx >= n || !expected_children.count(seq[idx])) {
                cout << "No\n";
                return 0;
            }

            // [G] Mark as visited and push to queue (BFS enqueue step)
            visited[seq[idx]] = true;
            q.push(seq[idx]);
            idx++;
        }
    }

    // [H] All nodes validated successfully
    cout << "Yes\n";
    return 0;
}
