class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,int prevans){
        if(i>=nums.size()) return 0;
        if(dp[i][prevans+1]!=-1) return dp[i][prevans+1];
        if(prevans==-1 || nums[i]>nums[prevans]){
            return dp[i][prevans+1]=max(1+find(nums,i+1,i),find(nums,i+1,prevans));
        }
        else return dp[i][prevans+1]=find(nums,i+1,prevans);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(nums,0,-1);
    }
};