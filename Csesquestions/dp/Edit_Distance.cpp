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
  string s1,s2;
  cin>>s1>>s2;
  vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
    //   base case
    for(int i=0;i<s1.length()+1;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<s2.length()+1;j++){
        dp[0][j]=j;
    }
    // transition state
    for(int i=1;i<s1.length()+1;i++){
        for(int j=1;j<s2.length()+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
                continue;
            }
            else{
            int a=1+dp[i-1][j-1];  // replace
            int b=1+dp[i-1][j];  // add
            int c=1+dp[i][j-1];  // remove
                dp[i][j]=min(a,min(b,c));
            }
        }
    }
    // final problem
    cout << dp[s1.length()][s2.length()] << endl;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;t=1;
  while (t--) {
    solve();
  }
}