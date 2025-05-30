#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    int a1,b1,a2,b2;
    int t1,t2,t3;

    cin>>k;
    for (int i=0; i<k; i++) {
        cin>>a1>>b1>>a2>>b2;
        t1 = a1 + b1;
        t2 = a2 + b2;
        t3 = t1 + t2;

        if (t3 % 2 == 0) {
            cout << t3 / 2 << endl;
        } else {
            cout << "impossible" << endl;
        }
    }


}