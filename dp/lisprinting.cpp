// ques->https://www.codingninjas.com/studio/problems/printing-longest-increasing-subsequence_8360670?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
using namespace std;

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	int maxi=0;
	int l=0;
	vector<int> dp(n,1);
	vector<int> hash(n,-1);
	for(int i=0;i<n;i++){
		hash[i]=i;
		for(int prev=0;prev<i;prev++){
			if(arr[i]>arr[prev] && 1+dp[prev]>dp[i]){
				dp[i]=dp[prev]+1;
				hash[i]=prev;
			}
		}
		maxi=max(maxi,dp[i]);
                if (maxi == dp[i]) {
                        l = i;
                }
        }
	vector<int>ans(maxi,0);
	int i=maxi;
	int j=l;
	while(i!=0){
		i--;
		ans[i]=arr[j];
		j=hash[j];
	}

	return ans;
}
