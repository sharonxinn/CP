// This program calculates the maximum number of teams that can be formed for the ACM ICPC world programming championship.
// Each team must have 3 students, and each student can participate at most 5 times in total.
// The program reads the number of students (n), the required number of future participations (k),
// and the number of times each student has already participated (y[i]).
// It counts how many students can participate at least k more times (i.e., 5 - y[i] >= k).
// The answer is the number of such students divided by 3 (since each team needs 3 members).
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> y(n);
    int eligible = 0;
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        // Count students who can participate at least k more times
        if (5 - y[i] >= k) eligible++;
    }
    // Output the maximum number of teams
    cout << eligible / 3 << endl;
    return 0;
}