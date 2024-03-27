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
  int a,b;
  cin>>a>>b;
    // dp[i][j] -->minimum for i*j;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
                }
        for(int v=1;v<=i-1;v++){
            dp[i][j]=min(dp[i][j],dp[v][j]+dp[i-v][j]+1);
        }
       for(int h=1;h<=j-1;h++){
            dp[i][j]=min(dp[i][j],dp[i][h]+dp[i][j-h]+1);
           }
     }
    }
    cout << dp[a][b] <<endl;

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