class Solution {
public:
    int dp[51][51][51];
    long long mod=1e9+7;
    long long find(vector<vector<int>>&grid,int i,int j,int moves){
        if(i>=grid.size() || j>=grid[0].size() || j<0 || i<0) return 1;
        if(moves==0) return 0;
        if(dp[i][j][moves]!=-1) return dp[i][j][moves];
        return dp[i][j][moves]=(find(grid,i+1,j,moves-1)+find(grid,i,j+1,moves-1)+find(grid,i-1,j,moves-1)+find(grid,i,j-1,moves-1))%mod;
    }
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>grid;
        grid.resize(n,vector<int>(m,0));
        memset(dp,-1,sizeof(dp));
        return find(grid,startRow,startColumn,maxMove)%mod;
    }
};