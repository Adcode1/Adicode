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
void solve2(){
    int n;cin>>n;
//   cout << "hlo" << endl;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int> dp(n,1);
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(arr[j]>arr[i])dp[j]=max(dp[j],dp[i]+1);
    }
  }
  cout << *max_element(dp.begin(),dp.end()) << endl;
}
void solve() {
  // TODO: Implement the solution
  int n;cin>>n;
//   cout << "hlo" << endl;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int> dp;
  for(int i=0;i<n;i++){
    if(dp.empty())dp.push_back(arr[i]);
    else if(dp.back()<arr[i])dp.push_back(arr[i]);
    else{
       int it=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
       dp[it]=arr[i];
    }
  }
     cout << dp.size() << endl;
//   cout << dp[0][0] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve2();
}