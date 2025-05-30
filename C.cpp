#include <bits/stdc++.h>
#include <cassert>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back

using namespace std;
using ll = long long;
using lld = long double;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fir); cerr << ","; _print(p.sec); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename U>
bool cmpr(const pair<T, U> &a, const pair<T, U> &b) {return a.second < b.second;}

void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

/*

n <= 60

we have a stack of trainees

each shout lowest wet get dry, all below it gets wet, how many shouts it takes for everone to get dry?

1 1 1

0 1 1

1 0 1

0 0 1

1 1 0

0 1 0

1 0 0

0 0 0

*/

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(int i{}; i < n; i++){
        char x;
        cin >> x;
        if (x == 'D'){
            a[i] = 0;
        }else a[i] = 1;
    }

    reverse(all(a));

    ll total = 0;
    for(int i{}; i < n; i++){
        if (a[i])
            total += (1LL << (i));
    }

    cout << total << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    //cin >> t;
    while (t--)
        solve();
}

