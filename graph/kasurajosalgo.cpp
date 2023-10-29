#include<bits./stdc++.h>
using namespace std;
vector<int> adj[100];
void dfs(int i,vector<int>&vis,vector<int>adj[],stack<int>&st){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(i);
}
void dfs3(int i,vector<int>&vis,vector<int>adj[]){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs3(it,vis,adj);
        }
    }
}
int kasuraju(int V,vector<int> adj[]){
    vector<int> vis(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    vector<int>trans[V];
    for(int i=0;i<V;i++){
        vis[i]=0;
        for(auto it:adj[i]){
            trans[it].push_back(i);
        }
    }
    int scc=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs3(node,vis,trans);
        }
    }
}