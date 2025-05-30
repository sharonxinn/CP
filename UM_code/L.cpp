#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        //ascendinf sort
        sort(a.begin(), a.end());
        bool possible = true;
        for (int i = 1; i < n; ++i) {   //remove smalest of these numbers
            if (a[i] - a[i-1] > 1) {    //he absolute difference between ai and aj, no more than 1
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}
