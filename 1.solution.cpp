#include <iostream>
using namespace std;

int my_max_segments(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n % 2 == 1) {  
        return n - my_max_segments(n - 1);
    } else {  
        return max(n - my_max_segments(n - 1), n - my_max_segments(n / 2));
    }
};

int main() {
    int t;
    cin >> t;
    int i = 0;
    while (i < t) {
        int n;
        cin >> n;
        cout << my_max_segments(n) << endl;
        i++;
    }
    return 0;
}