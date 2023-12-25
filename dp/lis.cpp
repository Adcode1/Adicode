// link->https://leetcode.com/problems/longest-increasing-subsequence/
// nlogn and o(n^2);
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int func(int i,int prev,vector<int>&nums,vector<vector<int>> &dp){
        if(i==nums.size()){           
            return 0;
        }
        int a=0;
        if(prev!=-1 and dp[i][prev]!=-1)return dp[i][prev];
        if(prev==-1 || nums[i]>nums[prev])
        {
            a=1+func(i+1,i,nums,dp);
        }
        int b=func(i+1,prev,nums,dp);
        if(prev==-1){
        return max(a,b);
        }
        return dp[i][prev]=max(a,b); 
    }
    int lengthOfLIS(vector<int>& nums){
            // vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
            // return func(0,-1,nums,dp);
            vector<int> ans;
            for(auto it:nums){
                auto y=lower_bound(ans.begin(),ans.end(),it);
                if(y==ans.end()){
                    ans.push_back(it);
                }else{
                    *y=it;
                }
            }
            return ans.size();
    }
};
