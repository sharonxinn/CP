#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        int diff = abs(a - b);
        //(diff + 9) / 10 is a common trick to perform integer ceiling division by 10.
        int moves = (diff + 9) / 10; // ceiling division
        cout << moves << endl;
    }
    return 0;
}