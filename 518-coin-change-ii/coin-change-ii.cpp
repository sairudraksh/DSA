class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int &target,int idx){
        if(target==0) return 1;
        if(idx>=nums.size()) return 0;
        if(dp[target][idx]!=-1) return dp[target][idx];
        int result=0;
        for(int i=idx;i<nums.size();i++){
            if(nums[i]<=target){
                target-=nums[i];
                result+=find(nums,target,i);
                target+=nums[i];
            }
        }
        return dp[target][idx]=result;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+1,vector<int>(coins.size()+1,-1));
        return find(coins,amount,0);
    }
};