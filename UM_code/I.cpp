#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int denominations[] = {5, 4, 3, 2, 1};
    int total = 0;
    for (int d : denominations) {
        total += n / d;
        n %= d;
    }
    cout << total << endl;
    return 0;
}