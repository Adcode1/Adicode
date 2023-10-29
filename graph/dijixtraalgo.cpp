// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// solve this also->https://leetcode.com/problems/path-with-minimum-effort/
// using pq --> --- 
#include<bits./stdc++.h>
using namespace std;

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e6;
        }
        dist[S]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,S});
        while(!pq.empty()){
            int top=pq.top().second;
            int path=pq.top().first;
            pq.pop();
            for(auto i:adj[top]){
                int sum = path+i[1];
                if(dist[i[0]] >sum){
                    dist[i[0]]=sum;
                    pq.push({sum,i[0]});
                }
            }
        }
        return dist;
    }

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       // {diff,{row,col}}
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 and col == m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr>=0 and newc>=0 and newr<n and newc<m){
                    int neweffort=max(diff,abs(heights[newr][newc]-heights[row][col]));
                    if(neweffort<dist[newr][newc]){
                        dist[newr][newc]=neweffort;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }
    }
};