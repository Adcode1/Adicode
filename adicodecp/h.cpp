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
  vector<int> v(n,0);
  set<int> s;
  for(int i=0;i<n;i++){
    cin>>v[i];
    s.insert(v[i]);
  }
  int mex=0;
  for(auto it:s){
    if(it>mex){
        break;
    }else{
        mex++;
    }
  }
  set<int> t;
  for(int i=0;i<mex;i++){
    t.insert(i);
  }
  int j=0;
 for(int i=0;i<n;i++){
    if(t.find(v[i])!=t.end()){
        t.erase(v[i]);
        if(t.empty()){
            j=i;
            break;
        }
    }
 }
  bool could=false;
  if(mex==0){
    could=true;
  }  
  set<int> w;
  for(int i=0;i<mex;i++){
    w.insert(i);
  }
  for(int a=j+1;a<n;a++){
    if(w.find(v[a])!=w.end()){
        w.erase(v[a]);
        if(w.empty()){
            could =true;
            break;
        }    
    }
  }
 if(!could){
    cout << -1 << endl;
 }
 else{
  cout << 2 << endl;
  cout << 1  << " "<< j+1 << endl;
  cout << j+2 <<" " <<n << endl;
 }


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