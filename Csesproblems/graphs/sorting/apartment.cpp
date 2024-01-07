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
void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  int i=0;
  int j=0;
  int a[n];
  int b[m];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int j=0;j<m;j++){
    cin>>b[j];
  }
  int cnt=0;
  sort(a,a+n);sort(b,b+m);
  while(i<n and j<m){
    if(a[i]-k<=b[j] and a[i]+k>=b[j]){
        cnt++;
        i++;
        j++;
    }
    else if(a[i]+k<b[j]){
        i++;
    }
    else{
        j++;
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