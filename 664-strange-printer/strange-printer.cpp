class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int find(string &s,int i,int j){
        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        int minimum=1+find(s,i+1,j);

        for(int k=j;k>i;k--){
            if(s[i]==s[k]){
                minimum=min(minimum,find(s,i+1,k-1)+find(s,k,j));
            }
        }

        return dp[i][j]=minimum;

    }
    int strangePrinter(string s) {
        n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(s,0,n-1);
    }
};