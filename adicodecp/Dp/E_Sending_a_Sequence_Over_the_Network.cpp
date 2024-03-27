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
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>dp(n+1,0);
  dp[0]=1;
  for(int i=1;i<=n;i++){
    // right segment
    if(i-arr[i-1]-1>=0 and dp[i-arr[i-1]-1]==1){
        dp[i]=1;
    }
    // left segment
    if(i+arr[i-1]<=n and dp[i-1]==1){
        dp[i+arr[i-1]]=1;
    }
  }
  if(dp[n]==1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
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