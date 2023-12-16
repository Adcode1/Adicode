#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int findWays(vector<int>& arr, int k){
	int n=arr.size();
	vector<int>prev(k+1,0);	
	vector<int>curr(k+1,0);
	prev[0]=1;curr[0]=1;
	// for(int j=0;j<k;j++) if(arr[n-1]>=j) prev[n-1]=1;
	for(int i=n-1;i>=0;i--){
		for(int sum=0;sum<=k;sum++){
			int take=0;
			int notake=prev[sum];
			if(arr[i]<=sum) take=prev[sum-arr[i]];
			curr[sum]=take+notake;
		}
		prev=curr;
	}
	return prev[k];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;for(auto e:nums)sum+=e;
        int k=target+sum;
        if(k%2!=0 || abs(target)>sum) return 0;
        return findWays(nums,(target+sum)/2);
    }
};

