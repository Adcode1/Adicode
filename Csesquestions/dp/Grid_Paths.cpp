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
vector<vector<char>> grid;
ll func(int i,int j,ll n,vector<vector<ll>>dp){
    ll ways=0;
    if(i==n || j==n)
    {   dp[i][j]=0;
        return 0;
    }
    if(grid[i][j]=='*'){
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==n-1 and j==n-1){
        dp[i][j]=1;
        return 1;
    }
    ways+=(func(i+1,j,n,dp))%N+(func(i,j+1,n,dp))%N;
    ways%=N;
    dp[i][j]=ways;
    return ways;
}
    // cout << "Hlo" << endl;


void solve() {
  // TODO: Implement the solution
  ll n;cin>>n;
  grid.resize(n,vector<char>(n));
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
        char a;
        cin>>a;
        grid[i][j]=a;
    }
  }
  vector<vector<ll>> dp2(n+1,vector<ll>(n+1,-1));
  vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
  for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
        if(grid[i][j]=='*'){
            dp[i][j]=0;
        }
        else if(i==n-1 and j==n-1){
            dp[i][j]=1;
        }
        else{
        int ways=dp[i+1][j]%N+dp[i][j+1]%N;
        ways%=N;
        dp[i][j]=ways;
        }
    }
  }
  cout << dp[0][0] << endl;
//   ll b=func(0,0,n,dp2);
//   cout << b << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t=1;
  while (t--) {
    solve();
  }
}