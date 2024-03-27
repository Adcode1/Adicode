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
void solve() {
  // TODO: Implement the solution
  int n,x;
  cin>>n>>x;
  vector<int> price(n);
  vector<int> page(n);
  for(int i=0;i<n;i++){
    cin>>price[i];
  }for(int i=0;i<n;i++){
    cin>>page[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  // base case
  for(int i=0;i<=x;i++){
    dp[0][x]=0;
  }
  for(int i=0;i<=x;i++){
    if(price[0]<=i){
      dp[1][i]=page[0];
    }
  }
  // transition
  // dp[i][k] length i with k coins how many pages
  for(int i=2;i<=n;i++){
    for(int cst=1;cst<=x;cst++){
      int take=0;
      int notake=dp[i-1][cst];
      if(price[i-1]<=cst)take=page[i-1]+dp[i-1][cst-price[i-1]];
      dp[i][cst]=max(take,notake);
    }
  }
  cout << dp[n][x] << endl;


}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;t=1;
  while (t--) {
    solve();
  }
}