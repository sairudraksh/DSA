class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(string &s1,string &s2,int i,int j){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+find(s1,s2,i+1,j+1);
        }
        else{
            return dp[i][j]=max(find(s1,s2,i+1,j),find(s1,s2,i,j+1));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        n=s1.length();
        m=s2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(s1,s2,0,0);
    }
};