#include <iostream>
using namespace std;
#include <vector>
int main(){
    int n=2;
    int a, b;
    vector<int>store;
    cin >>a>>b;
    int sizeofboard=a*b;

    store.push_back(sizeofboard / n); // Integer division, result will not have decimal or fraction

    cout << store.size() << endl;
}