class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<vector<int>>& grid,int i,int j,int &n,int &m){
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(find(grid,i+1,j,n,m),find(grid,i,j+1,n,m));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n, vector<int>(m, -1));
        return find(grid,0,0,n,m);
    }
};