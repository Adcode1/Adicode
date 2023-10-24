// stack using tough ques..
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

// Understanding use of multiset.. 

// ques2->https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,map<int,multiset<int>>>mp;
    void setrc(TreeNode* root,int r,int c){
        if(!root){
            return ;
        }
        mp[c][r].insert(root->val);
        setrc(root->left,r+1,c-1);
        setrc(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        setrc(root,0,0);
        vector<vector<int>> ans;
        for(auto it:mp){
            vector<int> temp;
            for(auto i:it.second){
                for(auto k:i.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};  