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
  int n;cin>>n;
  int sum=0;
  vector<int>coin;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    sum+=x;
    coin.push_back(x);
  }
  sort(coin.begin(),coin.end());
  vector<int> poss(sum+1,0);
  poss[0]=1;
  for(int i=0;i<n;i++){
    for(int val=sum;val>=coin[i];val--){
        poss[val]=max(poss[val-coin[i]],poss[val]);
    }
  }
  int cnt=0;
  for(int i=1;i<sum+1;i++)if(poss[i])cnt++;
  cout << cnt << endl;
  for(int i=1;i<sum+1;i++){
    if(poss[i]){
        cout << i << " ";
    }
  }



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