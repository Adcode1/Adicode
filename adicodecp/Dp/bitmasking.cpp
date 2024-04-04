// https://docs.google.com/document/d/1zuw8hBXHsiTYTH8u986fQhn8TWfpOk9BQBIRH3lo_W8/edit


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
vector<vector<int>> dp(21,vector<int>(1<<21,-1));

// dp[i][j] --> i th job to n th job with mask as j;
int func(int i,int mask,vector<vector<int>> cst,int n){
  if(i==n)return 0;
  
  int answer=1e9;
  if(dp[i][mask]!=-1)return dp[i][mask];
  for(int j=0;j<n;j++){
    if(mask&(1<<j)){
        answer=min(answer,cst[i][j]+func(i+1,mask^(1<<j),cst,n));// j th bit is on and off it for next iterations
    }
  }
  dp[i][mask]=answer;
  return answer;
}
void solve() {
  // TODO: Implement the solution

  int n;cin>>n;
  vector<vector<int>> cst(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>cst[i][j];
    }
  }
  cout << func(0,(1<<n)-1,cst,n) << endl;
  
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