class Solution {
public:
    vector<int>dp;
    int find(int i,int &n){
        if(i>n) return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=find(i+1,n)+find(i+2,n);
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return find(0,n);
    }
};