class Solution {
public:
    vector<vector<long long>>dp;
    long long find(string &s,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=find(s,i+1,j-1);
        }
        return dp[i][j]=1+min(find(s,i+1,j),find(s,i,j-1));
    }
    int minInsertions(string s) {
        int n=s.length();
        dp.resize(n+1,vector<long long>(n+1,-1));
        return (int)find(s,0,n-1);
    }
};