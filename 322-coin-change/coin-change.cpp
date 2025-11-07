class Solution {
public:
    int n;
    vector<int>dp;
    int find(vector<int>&coins,int target){
        if(target<0) return INT_MAX;
        if(target==0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            ans=min(ans,find(coins,target-coins[i]));
        }
        if(ans==INT_MAX) return dp[target]=INT_MAX;
        return dp[target]=ans+1;
    }
    int coinChange(vector<int>& coins, int target) {
        n=coins.size();
        dp.resize(target+1,-1);
        int a=find(coins,target);
        if(a==INT_MAX) return -1;
        else return a;
    }
};