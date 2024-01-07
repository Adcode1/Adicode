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
const int N=1e9+7;
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve() {
  // TODO: Implement the solution
  int n;cin>>n;
  int sum;cin>>sum;
  vector<int> c(n,0);
  for(int i=0;i<n;i++){
    cin>>c[i];
  }
  vector<ll> dp(1e6+2,0);
  dp[0]=1;
  for(int j=0;j<n;j++){
    for(int i=1;i<=sum;i++){
        if(c[j]<=i){
            dp[i]+=(dp[i-c[j]])%N;    
        }
        dp[i]%=N;
    }
  }
    cout << dp[sum] << endl;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    solve();
}