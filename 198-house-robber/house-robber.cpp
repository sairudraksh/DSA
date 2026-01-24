class Solution {
public:
    vector<int>dp;
    int find(vector<int>&nums,int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(find(nums,i+1),nums[i]+find(nums,i+2));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return find(nums,0);
    }
};