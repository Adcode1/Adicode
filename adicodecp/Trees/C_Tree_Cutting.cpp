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
vector<vector<int>> gr;

int dfs(int node,int parent,int mid,int& comp){
    int sz=1;
    // int cuts=0;
    for(auto it:gr[node]){
        if(it!=parent){
            sz+=dfs(it,node,mid,comp);
            }
    }
    if(sz>=mid){
        sz=0;
        comp++;
    }
    return sz;
}

bool yes(int k,int mid){
    int com=0;
    dfs(1,1,mid,com);
    if(com>=k+1)return true;
    return false;
}
void solve(){
  // TODO: Implement the solution
      // cout << "hlo" << endl;
    int n,k;cin>>n>>k;
    gr.erase(gr.begin(),gr.end());
    gr.resize((n+1));
    for(int i=1;i<n;i++){
      int x,y;cin>>x>>y;
      gr[x].push_back(y);
      gr[y].push_back(x);
    }
    int low=0;
    int high=n;
    int answer=0;
    while(low<=high){
      int mid=(low+high)/2;
      if(yes(k,mid)){
        answer=mid;
        low=mid+1;
      }else{
        high=mid-1;
      }
    } 
  cout << answer << endl;
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