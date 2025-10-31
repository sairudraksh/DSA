class Solution {
public:
    vector<vector<int>>dp;
    int find(int i,int j,vector<vector<int>>& nums){
        if(i==nums.size()-1) return nums[i][j];
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        return dp[i][j]=nums[i][j]+min(find(i+1,j+1,nums),find(i+1,j,nums));
    }
    int minimumTotal(vector<vector<int>>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,INT_MIN));
        return find(0,0,nums);
    }
};