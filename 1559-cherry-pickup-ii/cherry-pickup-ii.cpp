class Solution {
public:
    int n;
    int m;
    int dp[71][71][71];
    int find(vector<vector<int>>&grid,int i1,int j1,int i2,int j2){
        if(i1<0 || j1<0 || i1>=n || j1>=m || i2<0 || j2<0 || i2>=n || j2>=m) return 0;
        if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];
        if(j1==j2){
            return dp[i1][j1][j2]=grid[i1][j1]+max({find(grid,i1+1,j1+1,i2+1,j2),find(grid,i1+1,j1+1,i2+1,j2+1),find(grid,i1+1,j1+1,i2+1,j2-1),find(grid,i1+1,j1,i2+1,j2),find(grid,i1+1,j1,i2+1,j2+1),find(grid,i1+1,j1,i2+1,j2-1),find(grid,i1+1,j1-1,i2+1,j2),find(grid,i1+1,j1-1,i2+1,j2+1),find(grid,i1+1,j1-1,i2+1,j2-1)});
        }
        else {
            return dp[i1][j1][j2]=grid[i1][j1]+grid[i2][j2]+max({find(grid,i1+1,j1+1,i2+1,j2),find(grid,i1+1,j1+1,i2+1,j2+1),find(grid,i1+1,j1+1,i2+1,j2-1),find(grid,i1+1,j1,i2+1,j2),find(grid,i1+1,j1,i2+1,j2+1),find(grid,i1+1,j1,i2+1,j2-1),find(grid,i1+1,j1-1,i2+1,j2),find(grid,i1+1,j1-1,i2+1,j2+1),find(grid,i1+1,j1-1,i2+1,j2-1)});
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp, -1, sizeof(dp));
        return find(grid,0,0,0,m-1);
    }
};