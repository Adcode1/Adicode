#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int func(int ind,int amt,vector<int>&coins,vector<vector<int>> &dp){
       if(ind==coins.size()-1){
           if(amt%coins[coins.size()-1]==0) return dp[ind][amt]=amt/coins[coins.size()-1];
           return 1e9;
       }
       if(dp[ind][amt]!=-1)return dp[ind][amt];
       if(amt==0) return 0;
       if(amt<0) return 1e9;
       int take=1e9;
       if(coins[ind]<=amt) take=1+func(ind,amt-coins[ind],coins,dp);
       int notake=func(ind+1,amt,coins,dp);
       return dp[ind][amt]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=func(0,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};

