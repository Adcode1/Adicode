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
  int n,m;cin>>n>>m;
  vector<pair<int,int>> vpi;
  int arr[n];
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    arr[i]=a-1;
    vpi.push_back({a,i});
  }
  sort(all(vpi));
  ll cnt=1;
  for(int i=1;i<n;i++){
    if(vpi[i-1].second>vpi[i].second){
        cnt++;
    }
  }
  while(m--){
    int a,b;cin>>a>>b;
    int na=arr[a-1];
    int nb=arr[b-1];
    int temp=0;
    // na;
    if(na>=1){
        if(vpi[na-1].second>vpi[na].second){
            temp++;
        }
    }
    // na right
    if(na+1==nb){
        // nb and na right 
        if(vpi[na].second>vpi[na+1].second){
            temp++;
        }
       // nb right
       if(nb!=n-1 and vpi[nb].second>vpi[nb+1].second){
            temp++;
       } 
    }
    else{
        // na right
        if(na!=n-1 and vpi[na].second>vpi[na+1].second){
            temp++;
        }
        // nb
        if(vpi[nb-1].second>vpi[nb].second){
            temp++;
        } 
        // nb right
        if(nb!=n-1 and vpi[nb].second>vpi[nb+1].second){
            temp++;
       } 
    }
    swap(vpi[na].second,vpi[nb].second);
    swap(arr[a-1],arr[b-1]);
    int wa=arr[a-1];
    int wb=arr[b-1];
    int temp2=0;
    // na left;
    if(wa>=1){
        if(vpi[wa-1].second>vpi[wa].second){
            temp2++;
        }
    }
    // na right
    if(wa+1==wb){
        // nb and na right 
        if(vpi[wa].second>vpi[wa+1].second){
            temp2++;
        }
       // nb right
       if(wb!=n-1 and vpi[wb].second>vpi[wb+1].second){
            temp2++;
       } 
    }
    else{
        // na right
        if(wa!=n-1 and vpi[wa].second>vpi[wa+1].second){
            temp2++;
        }
        // nb
        if(vpi[wb-1].second>vpi[wb].second){
            temp2++;
        } 
        // nb right
        if(wb!=n-1 and vpi[wb].second>vpi[wb+1].second){
            temp2++;
       } 
    }
    cnt+=temp2-temp;
    cout << cnt << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    solve();
}
// MTL104
// 59 CS SENIORS
// CS  ->8
// MT->29
//
// MTL105
// CS 77
// MT 10
// 77:10 