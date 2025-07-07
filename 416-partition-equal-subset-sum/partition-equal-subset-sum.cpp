class Solution {
public:
    vector<vector<int>>dp;
    bool find(vector<int>& nums,int i,int &sum,int ans){
        if(i>=nums.size()) return false;
        if(dp[i][ans]!=-1) return dp[i][ans];
        int a=sum-ans;
        if(a==ans) return true;
        return dp[i][ans]=find(nums,i+1,sum,ans+nums[i]) | find(nums,i+1,sum,ans);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        dp.resize(n+1,vector<int>(sum+1,-1));
        return find(nums,0,sum,0);
    }
};