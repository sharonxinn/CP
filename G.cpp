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

adjacent swaps so that the first M adds up to S

if we're allowed to do S swap, is it possible

n <= 100

dp[i][j][k] = maximum at i, j crates taken k swaps

*/

const int MXN = 105;
const int MXK = MXN * (MXN-1) / 2;
ll dp[MXN][MXN][MXK];

void solve(){
    ll n, m, s;
    cin >> n >> m >> s;

    vll a(n);
    for(auto& i : a) cin >> i;

    for(int i{}; i < MXN; i++){
        for(int j{}; j < MXN; j++){
            for(int k{}; k < MXK; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    dp[0][0][0] = 0;

    int mn = INT_MAX;
    for(int i{1}; i <= n; i++){
        for(int j{}; j <= min((int)m,i); j++){
            // if we take it
            // j-1 has been taken
            // we need to put it at index j (1 index)
            // i is 1 index too
            if (j){
            int total_swaps = i-(j-1)-1;
            for(int k{total_swaps}; k < MXK; k++){
                if (dp[i-1][j-1][k-total_swaps] == -1) continue;

                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-total_swaps] + a[i-1]);
                if (dp[i][j][k] >= s){
                    mn = min(mn, k);
                }
            }

            }
            // if we dont take it
            for(int k{}; k < MXK; k++){
                if (dp[i-1][j][k] == -1) continue;
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
            }
        }
    }
    
    if (mn == INT_MAX) cout << -1;
    else cout << mn;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    //cin >> t;
    while (t--)
        solve();
}

