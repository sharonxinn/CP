#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main(){
    vector<int> sum;
    string s;
    cin >> s;
    
    for (char c : s) {
        if (c >= '1' && c <= '3') {
            sum.push_back(c - '0');   // Convert char to int
        }
    }
    // Sort the numbers ascending order
    sort(sum.begin(), sum.end());
    // Print the sorted numbers with '+'
    for (size_t i = 0; i < sum.size(); ++i) {
        cout << sum[i];
        if (i != (sum.size() - 1)) cout << "+";
    }
    cout << endl;
}

