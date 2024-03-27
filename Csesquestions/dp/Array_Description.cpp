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
const int Mod=1e9+7;
bool valid(int k,int m){
    if(k>=1 and k<=m){
        return true;
    }
    return false;
}
void solve() {
   int n,m;
   cin>>n>>m;
  // TODO: Implement the solution
   vector<int> arr(n,0);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//    dp[i][k]-->number of ways for length i and last element is k
    //base case
    for(int k=0;k<=m;k++){
        if(arr[0]==0 || arr[0]==k){
            dp[1][k]=1;
        }
    }
    // transition
    for(int i=2;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(arr[i-1]!=0 and arr[i-1]!=k){
                continue;
            }
            for(int prev=k-1;prev<=k+1;prev++){
                if(valid(prev,m)){
                    dp[i][k]+=(dp[i-1][prev])%Mod;
                    dp[i][k]%=Mod;
                }
            }
        }
    }// final ans;
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans+=(dp[n][i])%Mod;
    }
    cout << ans%Mod << endl;
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