#include <iostream>
using namespace std;
int main() {
    //In C++, long long is a data type used to store large integer values. It is a 64-bit signed integer
    long long n;
    cin >> n;
    if (n % 2 == 0)
        cout << n / 2 << endl;
    else
        cout << -(n + 1) / 2 << endl;
    return 0;
}
