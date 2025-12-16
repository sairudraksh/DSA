class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,bool taken){
        if(i>=nums.size()) return 0;
        if(dp[i][taken]!=-1) return dp[i][taken];
        if(taken){
            return dp[i][taken]=max(find(nums,i+1,true),nums[i]);
        }
        else{
            return dp[i][taken]=max(find(nums,i+1,taken),find(nums,i+1,true)-nums[i]);
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return find(prices,0,false);
    }
};