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
  vector<vector<string>> temp(6);
  for(int i=0;i<n;i++){
    string s;cin>>s;
    temp[s.length()].push_back(s);
  }
  ll ans=0;
  for(int l1=1;l1<6;l1++){
    for(int l2=1;l2<6;l2++){
        if((l1+l2)%2!=0)continue;
        map<int,int> cnt;
        int req=(l1+l2)/2;
        for(auto it:temp[l1]){
            int sum=0;
            for(int i=0;i<min(req,l1);i++)sum+=it[i]-'0';
            for(int i=req;i<l1;i++)sum-=it[i]-'0';
            cnt[sum]++;
        }
        for (string &s: temp[l2]){
                ll sum = 0;
                for (ll i = 0; i < min(l2, req); i++) sum += s[l2 - i - 1] - '0';
                for (ll i = req; i < l2; i++) sum -= s[l2 - i - 1] - '0';
                ans += cnt[sum];
            }
    }
  }
    cout << ans << endl;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t=1;
  while (t--) {
    solve();
  }
}