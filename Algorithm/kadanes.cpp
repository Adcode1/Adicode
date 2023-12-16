#include<bits./stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int sum=0;
        int maxi=-1e9;
        int arrstr=-1;
        int arrend=-1;
        int start=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0){start=i;}
            if(sum>maxi){
                maxi=sum;
                arrstr=start;
                arrend=i;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};
// the subarray is between the arrstr and arrend indexes;

/// https://leetcode.com/problems/maximum-subarray/