class Solution {
public:
    int n;
    vector<int>dp;
    int find(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+find(nums,i+2),find(nums,i+1));
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,-1);
        return find(nums,0);
    }
};