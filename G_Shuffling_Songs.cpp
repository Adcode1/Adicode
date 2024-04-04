// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double ld;
// #define pf push_front
// #define pb push_back
// #define F first
// #define S second
// #define loop(i, m, n) for (int i = m; i < n; i++)
// #define arep(i, v) for (auto i : v)
// #define all(x) (x).begin(), (x).end()
// #define yeah cout << YES << endl;
// #define noi cout << NO << endl;

// using namespace std;
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// vector<vector<int>> dp(17,vector<int>(1<<17,-1));
// map<int,pair<string,string>> mp;
// int func(int i,int mask,int n){
//     bool t=false;
//     if(dp[i][mask]!=-1)return dp[i][mask];
//     int answer=0;
//     for(int j=0;j<n;j++){
//         if(mask&(1<<j)){
//             if(mp[i].first==mp[j].first || mp[i].second==mp[j].second){
//                 answer=max(answer,1+func(j,mask^(1<<j),n));
//                 t=true;
//             }
//         }
//     }
//     if(!t){
//         dp[i][mask]=0;
//         return 0;
//     }
//     dp[i][mask]=answer;
//     return answer;
// }
// void solve() {
//   // TODO: Implement the solution
//   dp.erase(dp.begin(),dp.end());
//   mp.erase(mp.begin(),mp.end());
//   dp.resize(17,vector<int>(1<<17,-1));
//   int n;cin>>n;
//   for(int i=0;i<n;i++){
//     string g,w;
//     cin>>g>>w;
//     mp[i]={g,w};
//   }



//   cout << n-func(0,(1<<n)-1,n) << endl;
// }

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   int t;
//   cin >> t;
//   while (t--) {
//     solve();
//   }
// }
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solve(int n, const vector<pair<string, string>>& words) {
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    map<int, pair<string, string>> mp;

    for (int i = 0; i < n; ++i) {
        mp[i] = words[i];
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                bool t = false;
                for (int j = 0; j < n; ++j) {
                    if (mask & (1 << j)) {
                        if (mp[i].first == mp[j].first || mp[i].second == mp[j].second) {
                            dp[mask][i] = max(dp[mask][i], 1 + dp[mask ^ (1 << i)][j]);
                            t = true;
                        }
                    }
                }
                if (!t) {
                    dp[mask][i] = 0;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer = max(answer, dp[(1 << n) - 1][i]);
    }
    return n - answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<string, string>> words(n);
        for (int i = 0; i < n; ++i){
            cin >> words[i].first >> words[i].second;
        }
        cout << solve(n, words) << endl;
    }

    return 0;
}
