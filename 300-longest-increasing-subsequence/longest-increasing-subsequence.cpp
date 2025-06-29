class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,int &n,int prevans){
        if(i>=n) return 0;
        if(dp[i][prevans+1]!=-1) return dp[i][prevans+1];
        if(prevans==-1 || nums[i]>nums[prevans]){
            return dp[i][prevans+1]=max(1+find(nums,i+1,n,i),find(nums,i+1,n,prevans));
        }
        else return dp[i][prevans+1]=find(nums,i+1,n,prevans);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prevans=-1;
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(nums,0,n,prevans);
    }
};