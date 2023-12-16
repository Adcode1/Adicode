//->https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
// try to do first sc->o(n) tc->o(n);
// then do with sc->oc(1) ,tc->o(n);
// ques1->sc->o(1);
#include <bits/stdc++.h> 
using namespace std;
int frogJump(int n, vector<int> &heights){
    // int sum=0;
    vector<int> dp(n+1,-1);
    // int ans=give(1,heights,n,dp);
    dp[n]=0;
    int ahead=0;
    int before=0;
    for(int i=n-1;i>=1;i--){
        int curr;
        int one=before+abs(heights[i]-heights[i-1]);
        int two=1e9;
        if(i<n-1) two=ahead+abs(heights[i+1]-heights[i-1]);
        curr=min(one,two);
        ahead=before;
        before=curr;
    }
    return before;
}
// ques2->https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
// recursive-->
#include <bits/stdc++.h> 
using namespace std;
int give(int st,vector<int> &height,vector<int>&dp,int n,int k){
    if(st>=n) return 0;
    if(st==n-1) return dp[st]=abs(height[n-2]-height[n-1]);
    if(dp[st]!=-1) return dp[st];
    vector<int>temp;
    int sum=0;
    for(int i=1;i<=k;i++){
        if(st+i<=n){
        int a=abs(height[st-1]-height[st+i-1])+give(st+i,height,dp,n,k);
        temp.push_back(a);
        }
    }
    int mini=*min_element(temp.begin(),temp.end());
    return dp[st]=mini;
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n+1,-1);
    int ans=give(1,height,dp,n,k);
    return ans;
}
// tabulation->
#include <bits/stdc++.h> 
using namespace std;
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n+1,-1);
    // int ans=give(1,height,dp,n,k);
    dp[n]=0;
    for(int i=n-1;i>=1;i--){
        int mini=1e9;
        for(int j=1;j<=k;j++){
            if(i+j<=n){
                int a=abs(height[i+j-1]-height[i-1])+dp[i+j];
                mini=min(a,mini);
            }
        }
        dp[i]=mini;
    }
    return dp[1];
}
//1D ->DP
//2D ->DP



