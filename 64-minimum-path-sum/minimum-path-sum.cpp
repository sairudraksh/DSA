class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>& grid,int i,int j){
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int a=find(grid,i+1,j);
        int b=find(grid,i,j+1);
        if(a==INT_MAX && b==INT_MAX) return dp[i][j]=INT_MAX;
        return dp[i][j]=grid[i][j]+min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(grid,0,0);
    }
};