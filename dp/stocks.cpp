// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int func(vector<vector<int>>dp,vector<int>&prices,int i,int buy,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int prof=0;
        if(buy){
            prof=max(-prices[i]+func(dp,prices,i+1,0,n),func(dp,prices,i+1,1,n));
            return dp[i][buy]=prof;
        }else{
            prof=max(prices[i]+func(dp,prices,i+1,1,n),func(dp,prices,i+1,0,n));
            return dp[i][buy]=prof;
        }
    }
    int maxProfit(vector<int>& prices){
        // return func(dp,prices,0,1,prices.size());
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1)) ;
        int n=prices.size();
        // dp[n][0]=0;
        // dp[n][1]=0;
        vector<int> curr(2,-1);
        vector<int> ahed(2,-1);
        ahed[0]=0;ahed[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int prof=0;
                if(buy){
                    // prof=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                    // dp[i][buy]=prof;
                    prof=max(-prices[i]+ahed[0],ahed[1]);
                    curr[buy]=prof;
                }else{
                    // prof=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                    // dp[i][buy]=prof;
                    prof=max(prices[i]+ahed[1],ahed[0]);
                    curr[buy]=prof;
                }
            }
            ahed=curr;
        }
            // return dp[0][1];
            return curr[1]; 
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n=prices.size();
        prices.push_back(0);
        int i=0;
        int ans=0;
        int j=0;
        while(i!=n){
            if(prices[i+1] >prices[i]){
                i++;
            }
            else{
                ans+= prices[i]-prices[j];
                i++;
                j=i;
            }
        }
        return ans;
    }
};