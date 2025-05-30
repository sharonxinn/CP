#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int denominations[] = {100, 20, 10, 5, 1};
    int total = 0;
    for (int d : denominations) {
        total += n / d;
        n %= d;
    }
    cout << total << endl;
    return 0;
}