class Solution {
public:
    int n;
    int dp[101];
    int find(vector<int>&nums,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+find(nums,i+2),find(nums,i+1));
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(nums,0);
    }
};