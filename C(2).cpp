#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == 'D') {
            res = 2*res;
        } else {
            res = 2*res + 1;
        }
    }
    cout << res << '\n';
}