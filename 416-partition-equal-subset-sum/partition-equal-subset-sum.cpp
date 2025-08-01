class Solution {
public:
    vector<vector<int>>dp;
    bool find(vector<int>&nums,int i,int target){
        if(target==0) return true;
        if(target<0) return false;
        else if(i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool take=find(nums,i+1,target-nums[i]);
        bool notTake=find(nums,i+1,target);

        return dp[i][target]=(take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        dp.resize(n+1,vector<int>(target+1,-1));
        return find(nums,0,target);
    }
};