class Solution {
public:
    vector<int>dp;
    int find(int amount,vector<int>coins){
        if(amount==0) return 0;
        if(dp[amount]!=-2) return dp[amount];
        int result=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]<0) continue;
            result=min(result,find(amount-coins[i],coins));
        }
        if(result==INT_MAX) return dp[amount]=INT_MAX;
        return dp[amount]=1+result;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(amount+1,-2);
        int a=find(amount,coins);
        if(a==INT_MAX) return -1;
        else return a;
    }
};