class Solution {
public:
    vector<int>dp;
    int find(int n){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        if(n>=2) return dp[n]=(find(n-1) + find(n-2));
        else return dp[n]=find(n-1);
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return find(n);
    }
};