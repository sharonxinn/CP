#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }
    int sereja = 0, dima = 0;
    //two-pointer greedy selection
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        int pick;
        if (cards[l] > cards[r]) {
            pick = cards[l++];
        } else {
            pick = cards[r--];
        }

    //start from i=0
       if (i % 2 == 0) {
        sereja += pick;
    } else {
        dima += pick;
    }
    cout << sereja << " " << dima << endl;
}
}