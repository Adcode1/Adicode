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
ll func(int i,int j,int n,ll arr[]){
    if(j<0)return 0;
    if(i==n)return 0;
    if(i==j)return arr[i];
    ll a1=arr[i]+func(i+1,j-1,n,arr);
    ll a2=arr[i]+func(i+2,j,n,arr);
    ll a=min(a1,a2);
    ll b1=arr[j]+func(i+1,j-1,n,arr);
    ll b2=arr[j]+func(i,j-2,n,arr);
    ll b=min(b1,b2);
    return max(a,b);
}

void solve(){
  // TODO: Implement the solution
  int n;cin>>n;
  ll arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout << func(0,n-1,n,arr) << endl;
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