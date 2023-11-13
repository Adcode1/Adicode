//ques link-> https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
#include <bits/stdc++.h>
using namespace std;
class mst
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        //{wt,node}
        int sum=0;
        vector<int>vis(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int node=top.second;
            int wt=top.first;
            if(vis[node]==1){continue;}
            else{
                vis[node]=1;
                sum+=wt;
                for(auto it:adj[node]){
                    pq.push({it[1],it[0]});
                }
            }
            
        }
        return sum;
    }
};