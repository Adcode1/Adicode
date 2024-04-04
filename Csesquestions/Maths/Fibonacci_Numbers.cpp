#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define pf push_front
#define pb push_back
#define F first
#define S second
#define loop(i, m, n) for (ll i = m; i < n; i++)
#define arep(i, v) for (auto i : v)
#define all(x) (x).begin(), (x).end()
#define YES "YES"
#define NO "NO"

using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll mod=1e9+7;
vector<vector<ll>> multiply(vector<vector<ll>> m,vector<vector<ll>> n){
    vector<vector<ll>> ans(2,vector<ll>(2,0));
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            for(ll k=0;k<2;k++){
                ans[i][j] = (ans[i][j] + (m[i][k] * n[k][j]) % mod) % mod;
            }
        }
    }
    return ans;
}

vector<vector<ll>> func(vector<vector<ll>> A,ll n){
    if(n==1) return A;
    vector<vector<ll>> temp = func(A, n / 2);
    temp = multiply(temp, temp);
    if(n % 2 != 0) temp = multiply(temp, A);
    return temp;
}

void solve() {
    ll n;
    cin >> n;
    if(n==0){
        cout << 0 << endl;
        return ;
    }
    vector<vector<ll>> A = {{1,1},{1,0}};
    vector<vector<ll>> ans = func(A, n); 
    cout << ans[0][1] % mod << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
