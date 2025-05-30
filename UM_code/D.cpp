#include <iostream>
#include <set>  //USE SET INSTAEAD VECTOR 
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> levels;
    int p, q, x;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        cin >> x;
        levels.insert(x);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> x;
        levels.insert(x);
    }
    //If they can together pass all levels from 1 to n, then the set will contain exactly n unique elements.
    //levels.size() == n checks if every level from 1 to n is present in the set.
    // Check if the size of the set is equal to n
    if ((int)levels.size() == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;


}