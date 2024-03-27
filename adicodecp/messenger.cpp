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
  int n,l;cin>>n>>l;
  vector<pair<int,int>> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].second >> v[i].first;
  }
  sort(v.begin(),v.end());
  int ans=0;
  for(int i=0;i<n;i++){
      multiset<int> s;
      int curr=0;
      for(int r=i;r<n;r++){
        int temp=l-(v[r].first-v[i].first);
        curr+=v[r].second;
        s.insert(v[r].second);
        while(!s.empty() and curr>temp){
            int maxi=*s.rbegin();
            curr-=maxi;
            s.erase(s.find(maxi));
        }
        ans=max(ans,(int)s.size());
      }
  }
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