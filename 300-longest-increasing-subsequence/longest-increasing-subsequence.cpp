class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,int prev){
        if(i>=nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1 || nums[i]>nums[prev]){
            return dp[i][prev+1]=max(1+find(nums,i+1,i),find(nums,i+1,prev));
        }
        else{
            return dp[i][prev+1]=find(nums,i+1,prev);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(nums,0,-1);
    }
};