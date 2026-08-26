class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool find(vector<int>&nums,int &target,int sum,int i){
        if(sum==target) return true;
        if(sum>target) return false;
        if(i>=n) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=find(nums,target,sum+nums[i],i+1) || find(nums,target,sum,i+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0) return false;

        int target=sum/2;
        dp.resize(n+1,vector<int>(target+1,-1));
        return find(nums,target,0,0);
    }
};