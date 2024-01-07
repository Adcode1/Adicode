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
  vector<pair<int,int>> vpi;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    vpi.push_back({a,i});
  }
  sort(all(vpi));
  ll cnt=1;
  for(int i=1;i<n;i++){
    if(vpi[i-1].second>vpi[i].second){
        cnt++;
    }
  }
  cout << cnt << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    solve();
}