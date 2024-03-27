#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
// 0 matlb kahi se aaya hai
// 1 matlb direct nahi aayega ind count hoga
int solve(ll ind,ll cond,vector<vector<ll>> &freq,vector<ll>&v , vector<vector<ll>>&dp)
{
    if(ind == v.size())
    {
        return 0;
    }
    if(dp[ind][cond] !=-1)
    {
        return dp[ind][cond] ;
    }
    // cout<<"Here"<<endl;
    int ans  = cond+solve(ind+1,1,freq,v,dp)  ;
    int id = upper_bound(freq[v[ind]].begin(),freq[v[ind]].end(),ind) - freq[v[ind]].begin() ;

    if(id != freq[v[ind]].size())
    {
        ans = min(ans , solve(freq[v[ind]][id] , 0 ,freq , v , dp));
    }
    return dp[ind][cond] = ans ;
}
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    t = 1;
    cin>>t; 
    while(t--)
    {
        ll n;
        cin>>n;
        vector <ll> v(n) ;
        vector<vector<ll>>freq(n+1) ;
        for(ll i= 0 ; i<n ; i++)
        {
            cin>>v[i];
            freq[v[i]].pb(i);
        }

        vector<vector<ll>> dp(n+1,vector<ll>(2,-1)); 

        int ans = solve(0,1,freq,v,dp) ; // this function returns min number which can be saved from deletion

        cout<<n-ans<<endl;
    }
    return 0;
}