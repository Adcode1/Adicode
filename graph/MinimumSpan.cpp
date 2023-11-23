//ques link-> https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
#include <bits/stdc++.h>
using namespace std;
class mst
{   
    int N=1e8;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        //{wt,node}
        int sum=0;
        int count=0;
        vector<int> dist(V,N);
        vector<int>vis(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int top=it.second;
            int wt=it.first;
            vis[top]=1;
            if(wt>dist[top])
            {
                continue;
            }
            else{
                sum+=wt;
                count++;
                for(auto neigh:adj[top]){
                    int to=neigh[0];
				    int path=neigh[1];
				if(vis[to]==0 and dist[to]>path){
					dist[to]=path;
					pq.push({path,to});
				}			
			}
		    }
    }
    	if(count!=V){
			return -1;
			}
    	return sum;  
    }
};