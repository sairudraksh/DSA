class Solution {
public:
    int dp[10001];
    int find(int n){
        if(n==0) return 0;
        int ans=INT_MAX;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
           ans=min(ans,1+find(n-(i*i))); 
        }

        return dp[n]=ans;
    }
    int numSquares(int n) {
        long long num=sqrt(n);

        if(num*num==n){
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        return find(n);
    }
};