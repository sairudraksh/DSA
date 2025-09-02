class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<char>>& grid,int i,int j){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='0') return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min({find(grid,i,j+1),find(grid,i+1,j),find(grid,i+1,j+1)});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int maximum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maximum=max(maximum,find(matrix,i,j));
            }
        }
        return maximum*maximum;
    }
};