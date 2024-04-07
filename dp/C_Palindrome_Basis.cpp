// https://codeforces.com/problemset/problem/1673/C
// good question.....
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
const int mod=1e9+7;
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<ll> pal;
vector<ll> dp(40000+1,0);
bool check(int i){
    string s;
    // cout << "hlo" << endl;
    if(i%10==0)return false;
    while(i>0){
        char a;
        a=(i%10)+'0';
        s.push_back(a);
        i/=10;
    }
    // cout << s << endl;
   bool yes=true;
   for(int m=0;m<=s.length()/2;m++){
    if(s[m]!=s[s.length()-m-1]){
        yes=false;
    }
   }
   return yes;
}
void solve() {
  // TODO: Implement the solution
  int n;cin>>n;
  cout << dp[n] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x=40000+1;
  for(int i=1;i<=x;i++){
    if(check(i)){
        pal.push_back(i);
    }
  }
    // pal --> coins array;
    //   dp[i][j]--> number i using j coins
    // dp[i][j]-->dp[i][j-1]+dp[i-coin[i]][j];
    // base case-->0 coins -> 0 ways;
    dp[0]=1;
    for(int coin=0;coin<pal.size();coin++){
            for(int i=1;i<=4*1e4+1;i++){
                if(i>=pal[coin]){
                    dp[i]+=dp[i-pal[coin]]%mod;
                    dp[i]%=mod;
                }
            }
    }
    // for(int i=1;i<=5;i++){
    //     cout << dp[i] << " ";
    // }cout << endl;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}