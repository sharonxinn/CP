#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> vs;

    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        vector<int> v(a);

        for (int j = 0; j < a; j++)
        {
            cin >> v[j];
        }

        vs.push_back(v);
    }

    // even + odd = odd
    // odd + odd = even
    // even + even = even
    // adding odd changes parity
    // so check if number of odd elements is odd
    // let's say got 30 elements and 11 are odd
    // odd + odd = even <- for the 10 odds
    // so for the last odd, no matter which grp it adds to, parity will flip

    for (const auto v : vs)
    {
        int oc = 0;
        for (int i : v)
        {
            if (i % 2 == 1)
            {
                oc++;
            }
        }
        if (oc % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}