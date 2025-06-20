class Solution {
public:
    int find(string &text1,string &text2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]) {
            return dp[idx1][idx2]=1+find(text1,text2,idx1-1,idx2-1,dp);
        }
        return dp[idx1][idx2]=max(find(text1,text2,idx1-1,idx2,dp),find(text1,text2,idx1,idx2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(1001, vector<int>(1001,-1));
        int idx1=text1.size()-1;
        int idx2=text2.size()-1;
        return find(text1,text2,idx1,idx2,dp);
    }
};