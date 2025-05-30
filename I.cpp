#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

long long modInverse(long long a, long long mod) {
    long long res = 1;
    long long power = mod - 2;
    while (power > 0) {
        if (power % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        power /= 2;
    }
    return res;
}


long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    
    k = min(k, n - k); 

    long long res = 1;
    for (int i = 1; i <= k; i++) {
    
        res = res * (n - k + i) % MOD;

       
        res = res * modInverse(i, MOD) % MOD;
    }
    return res;
}

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n, m;
        cin >> n >> m; 

        vector<int> money(n);  
        for (int i = 0; i < n; ++i) {
            cin >> money[i];  
        }


        sort(money.begin(), money.end(), greater<int>());

        int bigger = money[m - 1];

        int total = count(money.begin(), money.end(), bigger);

        int selected = count(money.begin(), money.begin() + m, bigger);

   
        cout << comb(total, selected) << endl;
    }

    return 0;
}