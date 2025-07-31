class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    vector<vector<int>>dp;
    int find(vector<vector<int>>&nums,int i,int j){
        if(i<0 || i>=n || j>=m || j<0 || visited[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        visited[i][j]=1;

        int a=1;
        int b=1;
        int c=1;
        int d=1;

        if(i<n-1 && nums[i+1][j]>nums[i][j]) a=1+find(nums,i+1,j);
        if(j<m-1 && nums[i][j+1]>nums[i][j]) b=1+find(nums,i,j+1);
        if(i>0 && nums[i-1][j]>nums[i][j]) c=1+find(nums,i-1,j);
        if(j>0 && nums[i][j-1]>nums[i][j]) d=1+find(nums,i,j-1);
        visited[i][j]=0;
        return dp[i][j]=max({a,b,c,d});
    }
    int longestIncreasingPath(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int maximum=1;
        visited.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=find(nums,i,j);
                maximum=max(maximum,a);
            }
        }
        return maximum;
    }
};