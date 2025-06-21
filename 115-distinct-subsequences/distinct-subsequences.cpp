class Solution {
public:
    vector<vector<int>>dp;
    int find(string s1,string s2,int i,int j){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=find(s1,s2,i-1,j-1)+find(s1,s2,i-1,j);
        }
        return dp[i][j]=find(s1,s2,i-1,j);
    }
    int numDistinct(string s, string t) {
        dp.resize(1001,vector<int>(1001,-1));
        int n=s.size();
        int m=t.size();
        return find(s,t,n-1,m-1);
    }
};