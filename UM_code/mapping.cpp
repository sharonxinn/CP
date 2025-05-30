#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int balance = 0; // Mapping: tracks current bracket balance
        int min_balance = 0; // Searching: tracks minimum balance

        // Traverse the string to find the minimum balance
        for (char c : s) {
            if (c == '(') balance++;
            else balance--;
            // Searching: update minimum balance
            min_balance = min(min_balance, balance);
        }

        // The answer is the number of unmatched closing brackets at the start
        // Mapping: Each unmatched ')' at the start needs a move
        int moves = -min_balance;
        cout << moves << endl;
    }
    return 0;
}