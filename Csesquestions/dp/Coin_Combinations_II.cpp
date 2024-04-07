#include <bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
using namespace std; 
void solve() {
  // TODO: Implement the solution
  int n,x;cin>>n>>x;
  vector<ll> c(n);
  for(int i=0;i<n;i++){
    cin>>c[i];
  }
  vector<vector<ll>> dp(n+1,vector<ll>(x+1,0));
  // dp[i][k]---> total ways to get a sum of k using i to n-1 indexed coins 
  //and coins from 0 to i-1  are unusable;
  
  // base case -->
    for(int i=0;i<n;i++){
        dp[i][0]=1;// sum 0 only 1 way don't select
    }
  // transition
    for(int i=n-1;i>=0;i--){
  for(int sum=1;sum<=x;sum++){
        ll pick=0;
        if(sum>=c[i])pick=dp[i][sum-c[i]];
        ll skip=0;
        skip=dp[i+1][sum];
        dp[i][sum]=(skip+pick)%mod;
    }
  }
    // final problem
    cout << dp[0][x] << endl;
}
// space optimized //
void solve2(){
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    // dp[i][k] = number of ways to construct sum k
    // such that all coins before coin[i] are unusable
    
    // dp[i][k] -> dp[i + 1][k], dp[i][k - ci] 
    
    vector<ll> nextState(x + 1, 0); // dp[n][k]
    nextState[0] = 1; // dp[n][0] = 1;
 
    for(int i = n - 1; i >= 0; i--){
        vector<ll> currentState(x + 1, 0); // dp[i][k]
        currentState[0] = 1;
        for(int sum = 1; sum <= x; sum++){
            ll skipping = nextState[sum];
            ll picking = 0;
            if(a[i] <= sum){
                picking = currentState[sum - a[i]];
            }
            currentState[sum] = (skipping + picking) % mod;
        }
        // curentState[k] = dp[i][k]
        // nextState[k] = dp[i + 1][k]
        nextState = currentState;
    }
    cout << nextState[x] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve2();
}