class Solution {
public:
    vector<int>dp;
    int find(vector<int>&nums,int target){
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+(find(nums,target-nums[i]));
        }
        return dp[target]=sum;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.clear();
        dp.resize(1001,-1);
        int a=find(nums,target);
        return a;
    }
};