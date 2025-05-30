// ...existing code...
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // [Input Reading]
    int t;
    cin >> t;
    vector<long long> results; // [Use vector for output]

    while (t--) {
        long long n;
        cin >> n;

        // [Counting full cycles]
        long long blocks = n / 15;
        long long count = blocks * 3;

        // [Counting remainder]
        long long rem = n % 15;
        for (int i = 0; i < 15 && i <= rem; ++i) {
            if (i % 3 == i % 5) count++;
        }

        results.push_back(count);
    }

    // [Output]
    for (auto res : results) {
        cout << res << endl;
    }
    return 0;
}
