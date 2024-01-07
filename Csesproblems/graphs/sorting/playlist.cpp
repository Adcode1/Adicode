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
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int i=0;
  int j=0;
  set<int> s;
  int ans=0;
  while(i<n and j<n){
    while(j<n and s.find(arr[j])==s.end()){
      s.insert(arr[j]);
      ans=max(ans,j-i+1);
      j++;
    }
    while(j<n and s.find(arr[j])!=s.end()){
      s.erase(arr[i]);
      i++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
   solve();

}