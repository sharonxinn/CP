//n: number of officers
//q: number of queries
//pi: superior of officer i (for i = 2 to n)
//Each query ui ki: officer ui spreads a command, get the ki-th officer in command sequence

//Each line contains the answer to the corresponding query: the officer who receives the command in ki-th position from ui, or -1 if it doesn't exis

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

vector<int> tree[MAXN];       // [1] Adjacency list of the tree
vector<int> euler;            // [2] Flattened tree in DFS order
int in[MAXN];                 // [3] in[u] = index where u appears in euler[]
int subsize[MAXN];            // [4] Size of the subtree of u

// [5] DFS to flatten the tree and calculate in-time and subtree size
void dfs(int u) {
    in[u] = euler.size();     // Record when we enter node u
    euler.push_back(u);       // Add to Euler tour
    subsize[u] = 1;           // Count itself

    sort(tree[u].begin(), tree[u].end()); // To guarantee minimal index order

    for (int v : tree[u]) {
        dfs(v);
        subsize[u] += subsize[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // [6] Read tree structure
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    // [7] Start DFS from root officer (commander)
    dfs(1);

    // [8] Answer each query using in[] and subsize[]
    while (q--) {
        int u, k;
        cin >> u >> k;

        if (k > subsize[u]) {
            cout << -1 << '\n';
        } else {
            cout << euler[in[u] + k - 1] << '\n';
        }
    }

    return 0;
}
