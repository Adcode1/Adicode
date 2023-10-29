#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<pair<int,int>>v;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        while(pq.size()!=k){
            pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            int temp=pq.top().second;
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};