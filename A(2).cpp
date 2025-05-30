#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n) {
    if (n == 0) {
        return 0;
    }
    if ((n & 1) || (n > 4 && n % 4 == 0)) {
        return n - solve(n - 1);
    }
    return n - solve(n / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        ll res = solve(n);
        cout << res << '\n';
    }
}