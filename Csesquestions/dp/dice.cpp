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
  vector<ll>dp(1e6+1,0);
    dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=4;dp[4]=8;dp[5]=16;dp[6]=32;
    for(int i=7;i<=n;i++){
        for(int j=1;j<=6;j++){
            dp[i]+=(dp[i-j]%N);
        }
        dp[i]%=N;
    }
    cout << dp[n] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
   solve();
}