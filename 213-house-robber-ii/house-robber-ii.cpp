class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,bool taken){
        if(i>=n) return 0;
        if(i==n-1){
            if(taken) return 0;
            return nums[i];
        }
        if(dp[i][taken]!=-1) return dp[i][taken];
        if(i==0){
            return dp[i][taken]=max(nums[i]+find(nums,i+2,true),find(nums,i+1,false));
        }
        return dp[i][taken]=max(nums[i]+find(nums,i+2,taken),find(nums,i+1,taken));
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<int>(2,-1));
        return find(nums,0,false);        
    }
};