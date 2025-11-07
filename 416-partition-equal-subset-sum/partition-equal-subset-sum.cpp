class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool find(vector<int>&nums,int &target,int i,int sum){
        if(sum==target) return true;
        if(i>=nums.size()) return false;
        if(sum>target) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=find(nums,target,i+1,sum+nums[i]) || find(nums,target,i+1,sum);
    }
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        dp.resize(n+1,vector<int>(target+1,-1));
        return find(nums,target,0,0);
    }
};