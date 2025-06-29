class Solution {
public:
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int &n1,int &n2,int i,int j){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+find(s1,s2,n1,n2,i+1,j+1);
        }
        return dp[i][j]=max(find(s1,s2,n1,n2,i+1,j),find(s1,s2,n1,n2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        int i=0;
        int j=0;
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(text1,text2,n,m,i,j);
    }
};