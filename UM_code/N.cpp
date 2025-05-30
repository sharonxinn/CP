// The School №0 Team Formation Problem Solution
// Given n children, each with a skill (1=programming, 2=maths, 3=PE),
// form the maximum number of teams with one of each skill.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n); // t[i] stores the skill of child i (0-based)
    // Vectors to store indices (1-based) of children by skill
    vector<int> programmers, mathematicians, sportsmen;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        if (t[i] == 1) programmers.push_back(i + 1); // 1-based index
        else if (t[i] == 2) mathematicians.push_back(i + 1);
        else if (t[i] == 3) sportsmen.push_back(i + 1);
    }
    // The number of teams is limited by the smallest group
    int w = min((int)programmers.size(), min((int)mathematicians.size(), (int)sportsmen.size()));
    cout << w << endl;
    // Output the teams
    for (int i = 0; i < w; ++i) {
        // Each team: one programmer, one mathematician, one sportsman
        cout << programmers[i] << " " << mathematicians[i] << " " << sportsmen[i] << endl;
    }
    return 0;
}