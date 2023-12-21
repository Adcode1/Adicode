// prefix and
// question link->https://codeforces.com/contest/1878/problem/E
// youtube src->https://youtu.be/-DOsrJKm3TQ?si=uogFjvx8PQ4apqcp
// code->
//Aditya's cpp
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::vector<char> vc;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pi;
typedef std::vector<std::pair<int, int>> vpi;
typedef std::vector<std::vector<int, int>> vvi;
#define pf push_front
#define pb push_back
#define F first
#define S second
#define loop(i, m, n) for (int i = m; i < n; i++)
#define arep(i, v) for (auto i : v)
#define all(x) (x).begin(), (x).end()
const int N=2e5+1;
using namespace std;
int a[N];
int pref[N][32];
void build(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<32;j++){
      if(a[i]&(1<<j)){
        pref[i+1][j]=pref[i][j]+1;
      }
      else{
        pref[i+1][j]=pref[i][j];
      }
    }
  }
}
void solve() {
  // TODO: Implement the solution
  int n;cin>>n;
  loop(i,0,n){
    cin>>a[i];
  }
  build(n);
  int q;cin>>q;
  while(q--){
    int l,k;cin>>l>>k;
    if(a[l-1]<k){
      cout << -1 <<" ";
      continue;
      }
    int lo=l;int hi=n;
    int ans=l;
    while(hi-lo>1){
       int mid=(hi+lo)/2;
       int num=0;
       for(int j=0;j<32;j++){
        if(pref[mid][j]-pref[l-1][j]==(mid-l+1)){
          num+=(1<<j);
        }
       }
       if(num<k)hi=mid-1;
       else{
          lo=mid;
          ans=max(ans,mid);
       }
    }
    int num=0;
     for(int j=0;j<32;j++){
        if(pref[lo][j]-pref[l-1][j]==(lo-l+1)){
          num+=(1<<j);
        }}
    if(num>=k)ans=max(ans,lo);
    num=0;
     for(int j=0;j<32;j++){
        if(pref[hi][j]-pref[l-1][j]==(hi-l+1)){
          num+=(1<<j);
        }}
    if(num>=k)ans=max(ans,hi);
      cout << ans << " ";
  }cout << endl;
    
}
  

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}