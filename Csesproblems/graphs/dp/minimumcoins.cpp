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
const int N=1e9+7;

using namespace std;

void solve() {
  // TODO: Implement the solution
  int n;cin>>n;
  int sum;cin>>sum;
  vector<int> c(n,0);
  for(int i=0;i<n;i++){
    cin>>c[i];
  }
  vector<int> dp(1e6+2,1e7);
  dp[0]=0;
  for(int i=1;i<=sum;i++){
    int mini=1e7;
    for(int j=0;j<n;j++){
        if(c[j]<=i){
            mini=min(mini,1+dp[i-c[j]]);
        }
    }
    dp[i]=mini;
  }
  if(dp[sum]==1e7){
    cout << -1 << endl;
  }
  else{
    cout << dp[sum] << endl;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}