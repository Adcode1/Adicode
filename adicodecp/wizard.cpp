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
  int mx=0;
  for(int i=1;i<n;i++){
        cout<<"? "<<mx<<" "<<mx<<" "<<i<<" "<<i<<endl<<endl;
        cout.flush();
        char w;
        cin>>w;
        if(w=='<'){
            mx=i;
        }
  }
  vector<int> temp;
  int j=mx;
  for(int i=0;i<n;i++){
        cout << "?" <<" "<<mx << " "<< j <<" "<< mx <<" "<< i << endl << endl;
        cout.flush();
        char w;cin>>w;
        if(w=='<'){
            temp.push_back(-1);
            temp.push_back(i);
            j=i;
        }else if(w=='='){
            temp.push_back(i);
            j=i;
        }
  }
  vector<int> ans;
  for(int k=temp.size()-1;k>=0;k--){
    if(temp[k]==-1){
        break;
    }else{
        ans.push_back(temp[k]);
    }
  }
  int mn=ans[0];
  for(int i=1;i<ans.size();i++){
    cout <<"?" <<" " <<mn <<" " << mn << " " << ans[i] <<" " << ans[i] << endl << endl;
    cout.flush();
    char w;cin>>w;
    if(w!='<'){
        mn=ans[i];
    }
  }
   cout << "! " << mn << " " << mx << endl <<endl;
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