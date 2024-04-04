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
int sum(int num){
    int cnt=0;
    while(num>0){
        cnt+=num%10;
        num/=10;
    }
    return cnt;
}
void solve() {
  // TODO: Implement the solution
    int n,q;cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a1[n];
    int a2[n];
    int a3[n];
    for(int i=0;i<n;i++){
        a1[i]=sum(arr[i]);
    }
    for(int i=0;i<n;i++){
        a2[i]=sum(a1[i]);
    }for(int i=0;i<n;i++){
        a3[i]=sum(a2[i]);
    }
    vector<int> dp(n+1,0);
    while(q--){
        int type;cin>>type;
        if(type==1){
        int l;int r;
        cin>>l>>r;l--;r--;
        dp[l]++;dp[r]-=1;
        }
        else{
            int x;cin>>x;
            int cnt=0;
            for(int i=0;i<x;i++){
                cnt+=dp[i];
            }
            if(cnt>=3)cout << a3[x-1] << endl;
            else{
                if(cnt==2)cout << a2[x-1] << endl;
                if(cnt==1)cout << a1[x-1] << endl;
                if(cnt==0)cout << arr[x-1] << endl;
            }
        }
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
cout << "hlo" << endl;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}