#include <iostream>
#include <vector>
#include <bits/stdc++.h>  //cp libary
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string> r;

    while (t--) {
        int n;
        int k;

        cin >> n >> k;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        //binary search  !=v.end()
        if (find(v.begin(), v.end(), k) != v.end()) {
            r.push_back("YES");
        }
        else {
            r.push_back("NO");
        }
    }

    for (string s : r) {
        cout << s << endl;
    }

    return 0;
}