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
   ll arr[n];
   for(int i=0;i<n;i++){
    cin >>arr[i];
   }
   vector<ll> left(n,0);
   vector<ll> right(n,0);
   for(int i=0;i<n;i++){
    left[i]=arr[i]+i;
    right[i]=arr[i]-i;
   }
   for(int i=1;i<n;i++){
    left[i]=max(left[i],left[i-1]);
   }
   for(int i=n-2;i>=0;i--){
    right[i]=max(right[i],right[i+1]);
   }
   ll curr=0;
   ll ans=0;
   for(int i=1;i<n-1;i++){
        curr=arr[i]+left[i-1]+right[i+1];
        ans=max(ans,curr);
   }
    cout << ans <<endl;

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