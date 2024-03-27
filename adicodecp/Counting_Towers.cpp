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
const int N=1e9+7;
vector<vector<ll>> dp(1e6+1,vector<ll>(2,0));
void solve() {
  // TODO: Implement the solution
  ll n;cin>>n;
  // dp[i][0]= (i-1)th row->one horizontal climbing up
  // dp[i][1]=(i-1)th row-> two vertical climbing up
  dp[n][0]=dp[n][1]=1;
  for(int i=n-1;i>=1;i--){
    dp[i][0]=(2*dp[i+1][0]+dp[i+1][1])%N;
    dp[i][1]=(4*dp[i+1][1]+dp[i+1][0])%N;
  }
  cout << (dp[1][0]+dp[1][1])%N << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}