class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>& matrix,int i ,int j){
        if(j>=m || j<0) return INT_MAX;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=-100000) return dp[i][j];
        return dp[i][j]=matrix[i][j]+min({find(matrix,i+1,j+1),find(matrix,i+1,j-1),find(matrix,i+1,j)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int minimum=INT_MAX;
        dp.resize(n+1,vector<int>(m+1,-100000));
        for(int i=0;i<m;i++){
            minimum=min(minimum,find(matrix,0,i));
        }
        return minimum;
    }
};