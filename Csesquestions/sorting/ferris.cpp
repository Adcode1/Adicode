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
  int n,x;cin>>n>>x;
  ll p[n];
  for(int i=0;i<n;i++){
    cin>>p[i];
  }
  sort(p,p+n);
  ll ans=0;
  int i=0;int j=n-1;
  while(i<=j){
    if(p[i]+p[j]>x){
        ans++;
        j--;
    }else{
        i++;j--;
        ans++;
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