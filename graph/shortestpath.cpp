// for undirected graph // ques link ->https://www.codingninjas.com/studio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits./stdc++.h>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t){
	// adj vector
	unordered_map<int,vector<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// do bfs;
	unordered_map<int,bool> visited;	
	unordered_map<int,int> parent;
	// make parent array;
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(auto i:adj[f]){
			if(!visited[i]){
				visited[i]=true;
				parent[i]=f;
				q.push(i);
			}
		}
	}
	vector<int> ans;
	int j=t;
	while(j!=-1){
		ans.push_back(j);
		j=parent[j];
	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}
