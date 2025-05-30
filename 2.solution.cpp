#include <iostream>
#include <vector>
using namespace std;


bool canFit(vector<int>& episodes, int m, int maxSlot) {
    int slots = 1;
    int current = 0;

    for (int i = 0; i < episodes.size(); i++) {
        if (current + episodes[i] > maxSlot) {
            slots++;
            current = episodes[i];
        } else {
            current += episodes[i];
        }
    }

    return slots <= m;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> episodes(n);
    int maxDuration = 0, total = 0;

    for (int i = 0; i < n; i++) {
        cin >> episodes[i];
        if (episodes[i] > maxDuration) maxDuration = episodes[i];
        total += episodes[i];
    }

    int left = maxDuration, right = total;
    int answer = total;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canFit(episodes, m, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
