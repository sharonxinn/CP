//parity matching and minimum swaps 

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> ag;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> els;

        for (int j = 0; j < n; j++)
        {
            int el;
            cin >> el;
            els.push_back(el);
        }
        ag.push_back(els);
    }
    // can swap 2 elements per move
    // good if i mod 2 = a[i] mod 2 (for all i)
    // i must have same parity as a[i]
    // if a[i] = odd, a[i] mod 2 = 1, so i must also be odd
    // so count the number of mismatches for even and odd
    // if same number then can swap then will be good
    // else not good
    vector<int> ans;

    for (auto g : ag)
    {
        int em = 0;
        int om = 0;

        for (int i = 0; i < g.size(); i++)
        {
            if (g[i] % 2 != i % 2)
            {
                if (i % 2 == 0)
                {
                    em++;
                }
                else
                {
                    om++;
                }
            }
        }
        if (em != om) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(em);
        }
    }

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}