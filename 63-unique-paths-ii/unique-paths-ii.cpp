class Solution {
public:
    vector<vector<long long>>dp;
    long long find(vector<vector<int>>& nums,int i,int j,int &n,int &m){
        if(i>n-1 || j>m-1) return 0; 
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long a=0;
        long long b=0;
        if(i+1<=n-1 && nums[i+1][j]!=1) a=find(nums,i+1,j,n,m);
        if(j+1<=m-1 && nums[i][j+1]!=1) b=find(nums,i,j+1,n,m);
        return dp[i][j]=a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n=Grid.size();
        int m=Grid[0].size();
        if(Grid[0][0] == 1 || Grid[n-1][m-1] == 1) return 0;
        dp.resize(n+1,vector<long long>(m+1,-1));
        long long a=find(Grid,0,0,n,m);
        return (int)a;
    }
};

