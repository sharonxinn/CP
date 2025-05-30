#include <iostream>
using namespace std;
int main() {
    int k,n,w;
    cin>>k>>n>>w;
    int total=0;
    for (int i=1;i<=w;i++)
      {
        total =total+(i*k);
      }
    int borrow=total-n;
    if (borrow < 0) borrow = 0;
    cout <<borrow<<endl;
    return 0;

}
