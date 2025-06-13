class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        int a=n+1;
        vector<int>dp(a);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};