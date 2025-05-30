// each level got same number of chests
// input:
// a b 
// a = chest number, b = level where the chest is located
// 12 3 (find chest #12, 3 lines will follow)
// 9 3  (chest #, level)
// 2 1
// 10 4
// output:
// 4
// print level number where chest number a is at
// return -1 if impossible to confirm


#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    vector<pair<int, int>> chestCombos;
    for (int i = 0; i < b; i++) {
        int chestNum, chestLevel;

        cin >> chestNum >> chestLevel;

        chestCombos.push_back({chestNum, chestLevel});
    }

    set<int> validLevels;

    // from problem, xi <= 100 so c <= 100
    for (int c = 1; c <= 100; c++) {
        bool valid = true;

        for (int i = 0; i < chestCombos.size(); i++) {
            int chestNum = chestCombos[i].first;
            int chestLevel = chestCombos[i].second;

            // chest 10, 1 lvl 3 chests, expected ans lvl 4 
            // (10 - 1)/3 + 1 = 9/3 + 1 = 4

            // chest 26, 1 lvl 4 chests, expected ans lvl 7
            // (26-1)/4 + 1 = floor(6.xxx) + 1 = 7

            // so formula
            // ((chest number)/level) + 1 = expected level ans

            int expectedAns = ((chestNum - 1)/c) + 1;

            if (expectedAns != chestLevel) {
                valid = false;
                break;
            }
        }

        if (valid) {
            int levelChestA = ((a - 1)/c) + 1;
            validLevels.insert(levelChestA);
        }
    }

    if (validLevels.size() == 1) {
        cout << *validLevels.begin() << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}