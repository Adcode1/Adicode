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
  int n,m,k,d;
  cin>>n>>m>>k>>d;
  int arr[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
  }
  vector<int> temp;
  vector<int> dp(m,0);
  for(int i=0;i<n;i++){
    dp[m-1]=1;
    for(int j=m-2;j>=0;j--){
        int cst=arr[i][j]+1+dp[j+1];
        for(int w=1;w<=d+1;w++){
              if(j+w<m)cst=min(cst,1+arr[i][j]+dp[j+w]);
        }
        dp[j]=cst;
    }
    temp.push_back(dp[0]);
  }
//   for(auto it:temp){
//     cout << it << " ";
//   }cout << endl;
  ll ans=0;
  for(int i=0;i<k;i++){
    ans+=temp[i];
  }
  int i=0;
  int j=k-1;
  while(j+1<n){
    ll some=ans+temp[j+1]-temp[i];
    ans=min(ans,some);
    i++;
    j++;
  }
  cout << ans << endl;
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}