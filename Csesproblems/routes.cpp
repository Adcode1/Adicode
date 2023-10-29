// routes 1->https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000000
#define ll long long int
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int m;
    cin >> n >> m;
    vector<vector<ll>> adj[n+1]; // {u,v,wt};
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    // vector<ll> yes=dijkstra(n,adj,1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll>dist(n+1,INF);
    dist[1]=0;
    pq.push({0,1});
    while (!pq.empty())
    {
        ll go=pq.top().first;
        ll top=pq.top().second;
        pq.pop();
        if(go>dist[top]){
            continue;
        }
        for(auto neigh:adj[top]){
            ll path=neigh[1];
            ll v=neigh[0];
            ll sum=path+dist[top];
            if(sum<dist[v]){
                dist[v]=sum;
                pq.push({sum,v});
            }
        }
    }
    for(ll i=1;i<dist.size();i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}


// tc->(Elog(V));

