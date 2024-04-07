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
const ll mod=1e9+7;
void solve() {
  // TODO: Implement the solution
  ll n;cin>>n;
  ll sum=n*(n+1)/2;
  if(sum%2!=0){
    cout << 0 << endl;
  }
  else{
    sum/=2;
    // dp[i][j] -->ways from i to n with sum j,
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
    for(ll i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(ll i=n-1;i>=0;i--){
        for(ll j=0;j<=sum;j++){
            dp[i][j]=dp[i+1][j];
            if(j>=(i+1)){
                dp[i][j]=dp[i][j]+dp[i+1][j-(i+1)];
                }
           dp[i][j]%=mod;
        }
    }
    cout << ((dp[0][sum])*500000004)%mod << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}