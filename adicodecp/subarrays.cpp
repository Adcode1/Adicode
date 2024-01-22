// ques link->https://codeforces.com/contest/1888/problem/C

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
void solve() {
  // TODO: Implement the solution
   map<ll,ll> mp;
   ll n;cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   set<ll> foc,loc;
   for(int i=0;i<n;i++){
    if(mp[arr[i]]==0){
        foc.insert(i);
    }
    mp[arr[i]]++;
   }
    mp.clear();
    for(int i=n-1;i>=0;i--){
        if(mp[arr[i]]==0){
            loc.insert(i);
        }
        mp[arr[i]]++;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(foc.find(i)!=foc.end()){
            ans+=loc.size();
            if(loc.find(i)!=loc.end()){
                ans--;
            }
        }
        if(loc.find(i)!=loc.end()){
            loc.erase(i);
        }
    }
    ll so=0;
    for(int i=0;i<n;i++){
        if(mp[arr[i]]==1){
            so++;
        }
    }
    ans+=so;
    cout << ans << endl;
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