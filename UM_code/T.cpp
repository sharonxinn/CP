#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int test;
    vector<int>product;
    cin >> test;
    for (int i=0;i<test;i++)
    {
        int n;
        cin>>n;
        int a;
        product.clear(); // Clear vector for each test case
        for (int i=0;i<n;i++)
        {
            cin>>a;
            product.push_back(a);

        }
        //binary search
        int max_product = 0;
        for (int j = 0; j < n; j++) {
            int temp = product[j];
            product[j] = temp + 1;
            int multiply = 1;
            for (int s : product) {
                multiply *= s;
            }
            //find the maximum betwen max products, multiply
            max_product = max(max_product, multiply);
            product[j] = temp; // restore
        }
        cout << max_product << endl;
    }
}