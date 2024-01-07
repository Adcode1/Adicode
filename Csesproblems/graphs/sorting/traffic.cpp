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
  int x;int n;
  cin>>x>>n;
  set<int> pos;
  multiset<int> leng;
  pos.insert(0);
  pos.insert(x);
  leng.insert(x-0);
  for(int i=0;i<n;i++){
    int a;cin>>a;
    pos.insert(a);
    auto it=pos.find(a);
    int pval=*prev(it);
    int nval=*next(it);
    leng.erase(leng.find(nval-pval));
    leng.insert(nval-a);
    leng.insert(a-pval);
    cout << *leng.rbegin() <<" ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    solve();
}


// void solve() {
//   // TODO: Implement the solution
//   int x;int n;
//   cin>>x>>n;
//   int prev=0;
//   int curr=0;
//   int p;
//   cin>>p;
//   curr=p;
//   prev=p;
//   bool r=false;
//   bool l=false;
//   int maxi=max(p,x-p);
//   if(maxi==p){
//     l=true;
//     }
//   else 
//   {
//     r=true;}
//   cout << maxi <<" ";
//   int t=n-1;
//   while(t--){
//     int q;cin>>q;
//     curr=q;
//     if(curr>prev){
//         if(r){
//             int temp=curr-prev;
//             maxi=max(temp,maxi-temp);
//             cout << maxi << " ";
            
//             if(maxi!=temp){
//                 r=true;l=false;
//             }else{
//                 l=true;r=false;
//             }
//             prev=curr;
//         }
//         else{
//             cout << maxi << " ";
//         }
//     }
//     else{
//         if(l){
//             int temp=prev-curr;
//             maxi=max(temp,maxi-temp);
//             cout << maxi << " ";
//             if(maxi==temp){
//                 r=true;
//                 l=false;
//             }else{
//                 l=true;
//                 r=false;
//             }
//             prev=curr;
//         }
//         else{
//             cout << maxi << " ";
//         }
//     }
//   }cout << endl;
// }