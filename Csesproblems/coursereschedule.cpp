#include<bits/stdc++.h>
using namespace std;
void topo(int s,vector<int> &vis,vector<int> adj[],vector<int> &ans,vector<int> pathvis,bool &t){
	vis[s]=1;
	pathvis[s]=1;
	for(auto neigh:adj[s]){
		if(vis[neigh]==0){
			topo(neigh,vis,adj,ans,pathvis,t);
		}
		else if(vis[neigh]==1 and pathvis[neigh]==1){
			t=true;
		}
	}
	pathvis[s]=0;
	ans.push_back(s);
}
int main(){
	int n;int m;
	cin>>n>>m;
	vector<int> adj[n+1];
	vector<int> pathvis(n+1,0);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		adj[b].push_back(a);
	}
	vector<int> ans;
	bool t=false;
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			topo(i,vis,adj,ans,pathvis,t);
		}
	}
	if(t){
		cout << "IMPOSSIBLE" <<endl;
	}
	else{
		for(int i=0;i<ans.size();i++){
			cout << ans[i] << " ";
		}cout << endl;
	}
}