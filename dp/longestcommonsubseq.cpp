#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int k=0;k<=text2.size();k++){
            dp[0][k]=0;
        }
        for(int k=0;k<=text1.size();k++){
            dp[k][0]=0;
        }
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

// part2->getting the lcs 
// link-->https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
// o(n+m) ->worst case;
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	       vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int k=0;k<=s2.size();k++){
            dp[0][k]=0;
        }
        for(int k=0;k<=s1.size();k++){
            dp[k][0]=0;
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
                }
            }
        }
        int h;
        h=dp[s1.size()][s2.size()];
        string s="";
        for(int i=0;i<h;i++){
            s+=".";
        }
        int index=h-1;
        int i=s1.size();int j=s2.size();
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                s[index]=s1[i-1];
                i--;j--;index--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        return s;
}


// follow on question do for this stuff for substring rather than for subsequences..
// link->https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf