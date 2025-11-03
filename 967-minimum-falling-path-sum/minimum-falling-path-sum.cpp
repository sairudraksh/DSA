class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>&grid,int i,int j){
        if(i>=n || i<0 || j>=m || j<0) return INT_MAX;
        if(i==n-1) return grid[i][j];
        if(dp[i][j]!=-100000) return dp[i][j];
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        a=find(grid,i+1,j);
        b=find(grid,i+1,j+1);
        c=find(grid,i+1,j-1);

        if(a==INT_MAX && b==INT_MAX && c==INT_MAX) return dp[i][j]=INT_MAX;
        return dp[i][j]=grid[i][j]+min({a,b,c});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int ans=INT_MAX;
        dp.resize(n+1,vector<int>(m+1,-100000));
        for(int i=0;i<m;i++){
            ans=min(ans,find(matrix,0,i));
        }
        return ans;
    }
};