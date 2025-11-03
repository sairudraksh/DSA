class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>&grid,int i,int j){
        if(i>=n || j>=m) return 0;
        if(grid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=find(grid,i+1,j)+find(grid,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(grid,0,0);
    }
};