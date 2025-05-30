// For each test case, the answer is simply n / 2.
// This is because the largest GCD for any pair (a, b) in [1, n] is achieved with (n, n/2).

#include <iostream>
using namespace std;

// For each test case, the answer is simply n / 2.
// This is because the largest GCD for any pair (a, b) in [1, n] is achieved with (n, n/2).

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n / 2 << endl;
    }
    return 0;
}