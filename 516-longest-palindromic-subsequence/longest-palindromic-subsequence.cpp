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
    int longestPalindromeSubseq(string s1) {
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n=s1.length();
        int i=0;
        int j=0;
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(s1,s2,n,n,i,j);
    }
};