class Solution {
public:
    int n;
    int m;
    int dp[501][501][3];
    int find(vector<vector<int>>& grid,int i,int j,int k){
        if(i==n-1 && j==m-1){
            if(grid[i][j]<0){
                if(k>0) return 0;
                else return grid[i][j];
            }
            return grid[i][j];
        }
        if(i>=n || j>=m) return INT_MIN;
        if(dp[i][j][k]!=INT_MAX) return dp[i][j][k];
        int a=INT_MIN;
        int b=INT_MIN;
        a=max(find(grid,i+1,j,k),find(grid,i,j+1,k));
        if(a!=INT_MIN) a+=grid[i][j];
        if(grid[i][j]<0){
            if(k>0){
                b=max(find(grid,i+1,j,k-1),find(grid,i,j+1,k-1));
            }
        }
        return dp[i][j][k]=max(a,b);
    }
    int maximumAmount(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k] = INT_MAX;
            }
        }
    }
        return find(grid,0,0,2);
        
    }
};