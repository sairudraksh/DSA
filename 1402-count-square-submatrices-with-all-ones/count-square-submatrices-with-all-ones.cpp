class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>& matrix,int i,int j){
        if(i>=n || j>=m) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min({find(matrix,i+1,j),find(matrix,i+1,j+1),find(matrix,i,j+1)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int count=0;
        dp.resize(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=0;
                if(matrix[i][j]==1) a=find(matrix,i,j);
                count+=a;
            }
        }
        return count;
    }
};