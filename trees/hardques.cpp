class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        if(n==1){
            return ans;
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;

            while(!st.empty() and heights[i]>st.top()){
                st.pop();
                cnt++;
            }
            ans[i]=cnt;
            if(st.empty()){
                ans[i]=cnt-1;
            }
            st.push(heights[i]);
        }
        return ans;
    }
 

};
//Input: heights = [10,6,8,5,11,9]
//Output: [3,1,2,1,1,0]
// invariant kya hain -- voh yeh hain ki for a index i we will get a stack which contains element greater than it in increasing order
//means the maximum at bottom and so on or yehi required tha think carefully baaki toh.
//https://leetcode.com/problems/number-of-visible-people-in-a-queue/