#include<bits./stdc++.h>
using namespace std;
class Solution
{
vector<vector<int>> v;
public:
    int time = 0;
// Function to return a list of lists of integers denoting the members
// of strongly connected components in the given graph.
void scc(int i, vector<int> &id, vector<int> &ll, vector<bool> &onstack, stack<int> &stk, vector<int> adj[])
{
    id[i] = ll[i] = ++time;
    onstack[i]=true;
    stk.push(i);
    for(auto neigh:adj[i]){
        if(id[neigh]==-1){
            scc(neigh,id,ll,onstack,stk,adj);
            ll[i]=min(ll[i],ll[neigh]);
        }
        else if(onstack[neigh]){
            ll[i]=min(ll[i],ll[neigh]);
        }
    }
    if(ll[i]==id[i]){
        vector<int> w;
        while(stk.top()!=i){
            int j=stk.top();
            onstack[j]=false;
            stk.pop();
            w.push_back(j);
        }
        int j=stk.top();
        onstack[j]=false;
        stk.pop();
        w.push_back(j);
        sort(w.begin(),w.end());
        v.push_back(w);
    }
}

vector<vector<int>> tarjans(int n, vector<int> adj[])
{
    vector<int> id(n, -1);
    vector<int> ll(n, -1);
    vector<bool> onstack(n, false);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (id[i] == -1)
        {
            scc(i, id, ll, onstack, stk, adj);
        }
    }
    sort(v.begin(), v.end());
    return v;
}
};