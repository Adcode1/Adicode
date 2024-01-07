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

using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<int> give(int n){
        int a=n;
      vector<int> dig;
        while(a){
        int b=a%10;
        dig.push_back(b);
        a/=10;
        }
        return dig;
}
void solve() {
  // TODO: Implement the solution
  vector<int> dp(1e6+1,1e6);
  int n;cin>>n;
  for(int i=1;i<=9;i++){
    dp[i]=1;
  }
  for(int i=10;i<=n;i++){
     vector<int>digi;
     digi=give(i);
     int ans=1e6;
     for(int j=0;j<digi.size();j++){
        int temp=i-digi[j];
        ans=min(ans,dp[temp]+1);
     }
     dp[i]=ans;
  }
   cout << dp[n] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    solve();
}