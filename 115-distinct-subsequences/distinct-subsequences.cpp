class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(string &s,string &t,int i,int j){
        if(j>=m) return 1;
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0;
        int b=0;
        if(s[i]==t[j]){
            a=find(s,t,i+1,j+1);
        }
        b=find(s,t,i+1,j);
        return dp[i][j]=a+b;
    }
    int numDistinct(string s, string t) {
        n=s.length();
        m=t.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(s,t,0,0);
    }
};