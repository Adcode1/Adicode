//ques link->https://codeforces.com/problemset/problem/295/B
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
using db=double;
const int N=510;
ll dist[N][N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            dist[i][j]=x;
        }
    }
    vector<int>order;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        order.push_back(a);
    }
    reverse(order.begin(),order.end());
    vector<ll> yes;
    for(int k=0;k<n;k++){
        int k_v=order[k];
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll ans=dist[i][k_v]+dist[k_v][j];
            dist[i][j]=min(dist[i][j],ans);
        }
    }
    ll sum=0;
     for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            sum+=dist[order[j]][order[i]];
        }
     }
     yes.push_back(sum);
    }
    reverse(yes.begin(),yes.end());
    for(auto a:yes){
        cout << a << " ";
    }   
    cout << endl;
}