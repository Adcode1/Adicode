#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define pf push_front
#define pb push_back
#define F first
#define S second
#define loop(i, m, n) for (int i = m; i < n; i++)
#define arep(i, v) for (auto i : v)
#define all(x) (x).begin(), (x).end()
#define yeah cout << YES << endl;
#define noi cout << NO << endl;

using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll mod=1e9+7;

ll fastpow(ll a,ll b){
    if(b==0)return 1;
    if(b==1)return a;
    ll tmp=fastpow(a,b/2);
    if(b%2==0) return (tmp*tmp)%mod;
    else return ((a*((tmp*tmp)%mod))%mod)%mod;
}
void solve() {
  // TODO: Implement the solution
  ll a;ll b;
  cin>>a>>b;
  ll ans=fastpow(a,b);
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while (t--) {
    solve();
  }
}