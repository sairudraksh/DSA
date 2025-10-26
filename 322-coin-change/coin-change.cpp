class Solution {
public:
    vector<int>dp;
    int find(vector<int>nums,int target){
        if(target==0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(target>=nums[i]){
                target-=nums[i];
                int a=find(nums,target);
                target+=nums[i];
                if(a!=INT_MAX){
                    ans=min(ans,1+a);
                }
            }
        } 
        return dp[target]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        int a=find(coins,amount);
        if(a==INT_MAX) return -1;
        return a;
    }
};