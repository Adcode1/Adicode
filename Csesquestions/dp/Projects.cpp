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
  ll n;cin>>n;
  vector<pair<ll,pair<ll,ll>>> vl;
  vector<ll> start;
  // vl->st,{end,rew};
  for(ll i=0;i<n;i++){
    ll st;ll en;cin>>st>>en;
    ll rew;cin>>rew;
    start.push_back(st);
    vl.push_back({st,{en,rew}});
    // sta.push_pack(st);
  }
  sort(start.begin(),start.end());
  sort(vl.begin(),vl.end());
//   for(auto it:vl){
//     cout << it.first <<"->"<< it.second.first <<" "<< it.second.second <<endl;
//   }
  vector<ll> dp(n+1,0);
  // ending ->sorted end value;
  // project p0,p1,p2....pn-1;
  // dp[i]=largest poss reward for [pi,pi+1,p3...pn]
  // (P1,P2,P3...PN)-->i am on last Pi Projects-->1 way is not to consider PN ==>dp[i+1]
  // other ways is consider Pi if considered dp[i]=rew[i] + dp[j] ;; j--> biggest element such that start of j is after end of i,
  // answer would be dp(0)
  // base case i==n no project left and n project done hence 0;
    dp[n]=0;
    // transition
    for(int i=n-1;i>=0;i--){
        dp[i]=dp[i+1];
        ll nxt=upper_bound(start.begin()+i,start.end(),vl[i].second.first)-start.begin();
        dp[i]=max(dp[i],vl[i].second.second+dp[nxt]); // invariant nxt should be after i,
    }
// cout << cnt << endl;
    // for(auto it:dp){
    //     cout << it <<" ";
    // }
    cout << dp[0] << endl;

}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}