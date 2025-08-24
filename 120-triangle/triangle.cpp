class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<vector<int>>& nums,int i,int j){
        if(i==nums.size()-1) return nums[i][j];
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        return dp[i][j]=min(nums[i][j]+find(nums,i+1,j),nums[i][j]+find(nums,i+1,j+1));
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        dp.resize(n+1,vector<int>(n+1,INT_MIN));
        return find(triangle,0,0);
    }
};