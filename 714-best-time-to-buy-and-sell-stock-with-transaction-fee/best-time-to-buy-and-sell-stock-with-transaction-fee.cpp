class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int &fee,int i,bool holding){
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i][holding]!=-1) return dp[i][holding];
        if(holding){
            return dp[i][holding]=max(nums[i]+find(nums,fee,i+1,false),find(nums,fee,i+1,true));
        }
        else{
            return dp[i][holding]=max((find(nums,fee,i+1,true)-nums[i])-fee,find(nums,fee,i+1,false));
        }

    }
    int maxProfit(vector<int>& nums, int fee) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(2,-1));
        return find(nums,fee,0,false);
    }
};