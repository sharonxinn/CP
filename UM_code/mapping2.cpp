#include <iostream>
using namespace std;

// Important Concept 1: The optimal cell to gather all figures is the center cell of the board.
// Important Concept 2: The minimum number of moves is the sum of Manhattan distances from all cells to the center.
// Important Concept 3: For an n x n board (n odd), the answer is: sum_{k=1}^{n/2} 8 * k^2

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long res = 0;
        // Loop over each "layer" around the center
        for (long long k = 1; k <= n / 2; ++k) {
            // Each layer k has 8*k cells, each at distance k from the center
            res += 8 * k * k;
        }
        cout << res << endl;
    }
    return 0;
}