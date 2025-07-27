class Solution {
public:
    vector<vector<int>>dp;
    int maze(int sr,int sc,int &er,int &ec){
        if(sr>=er || sc>=ec) return 0;
        else if(sr==er-1 && sc==ec-1) return 1;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        int rightways=maze(sr,sc+1,er,ec);
        int downways=maze(sr+1,sc,er,ec);
        int totalways=rightways+downways;
        return dp[sr][sc]=totalways;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        return maze(0,0,m,n);
    }
};