class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(string &s,int i,int j){
        if(i==j) return 1;
        else if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=2+find(s,i+1,j-1);
        }
        else{
            return dp[i][j]=max(find(s,i+1,j),find(s,i,j-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(s,0,n-1);
    }
};