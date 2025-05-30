//First line: Integer t — number of test cases.
//Line 1: Integer n — number of vertices in the tree.
//Line 2: n integers — danger values a[1] ... a[n].
//Next n-1 lines: two integers u v — an undirected edge between vertices u and v.

//Output For each test case, print n integers — the threat values for each vertex from 1 to n.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void dfs(int u, int parent, const vector<vector<int>>& adj,
         const vector<ll>& danger, vector<ll>& even, vector<ll>& odd) {
    even[u] = danger[u];
    odd[u] = -danger[u];

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, adj, danger, even, odd);
        even[u] = max(even[u], danger[u] - odd[v]);
        odd[u] = max(odd[u], -danger[u] + even[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> danger(n);
        for (int i = 0; i < n; ++i) cin >> danger[i];

        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v; // convert to 0-based
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> even(n), odd(n);
        dfs(0, -1, adj, danger, even, odd);

        for (int i = 0; i < n; ++i) {
            cout << even[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
