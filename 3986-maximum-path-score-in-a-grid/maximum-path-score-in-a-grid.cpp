class Solution {
public:
    short dp[201][201][501];
    int n;
    int m;
    int find(vector<vector<int>>&grid,int i,int j,int curr,int &k){
        if(curr>k) return SHRT_MIN;
        if(i>=n || j>=m || i<0 || j<0) return SHRT_MIN;

        int num=0;
        if(grid[i][j]==0) num=0;
        else num=1;

        if(i==n-1 && j==m-1){
            curr+=num;
            if(curr>k) return SHRT_MIN;
            else return grid[i][j];
        }

        if(dp[i][j][curr]!=-1) return dp[i][j][curr];
        

        return dp[i][j][curr]=grid[i][j]+max({find(grid,i+1,j,curr+num,k),find(grid,i,j+1,curr+num,k)});
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int a=find(grid,0,0,0,k);
        if(a<=SHRT_MIN/2) return -1;
        return a;
    }
};