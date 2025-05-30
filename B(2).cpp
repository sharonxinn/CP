#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        int n = s.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (res == 0 || s[i] == 'A') {
                res++;
            } else {
                res--;
            }
        }
        cout << res << '\n';
    }
}