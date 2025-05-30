#include <bits/stdc++.h>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    int s = 0;

    for (s = 0; s < n; s++) {
        // keep first element + remove last element  ||  remove 1st element + keep last element   
        // when s = 1 
        // a[0] + a[n-2] || a[n-1] + a[1]
        if ((a[0] + a[n-s-1]) % 2 == 0 || (a[n-1] + a[s]) % 2 == 0) {
            break;
        }
    }
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}