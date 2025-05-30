#include <iostream>
using namespace std;
#include <vector>
int main(){
    int n;
    int a, b, c;
    vector<int>write;
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a+b+c >=2)
            write.push_back(1);
        
    }
    cout << write.size() << endl;
}