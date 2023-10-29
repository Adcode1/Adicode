#include<bits./stdc++.h>
using namespace std;

bool bellman_ford(int source,int n,vector<vector<int>> &edges){
	vector<int>d(n,INT_MAX);
	d[source]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<edges.size();j++){
			int u=edges[j][0];
			int v=edges[j][1];
			int wt=edges[j][2];
			if(d[u]!=INT_MAX and d[u]+wt<d[v]){
				d[v]=d[u]+wt;
			}
		}
	}
		for(int j=0;j<edges.size();j++){
			int u=edges[j][0];
			int v=edges[j][1];
			int wt=edges[j][2];
			if(d[u]!=INT_MAX and d[u]+wt<d[v]){
				return true;
			}
		}
	return false;	
}
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	for(int i=0;i<n;i++){
		if(bellman_ford(i,n,edges)){
			return true;
		}
	}
	return false;	    
	}
};