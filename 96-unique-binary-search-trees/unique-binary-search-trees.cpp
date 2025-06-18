class Solution {
public:
    vector<int>dp;
    int find(int n){
        if(n==0 || n==1) return dp[n]=1;
        if(n==2) return dp[n]=2;
        if(dp[n]!=-1) return dp[n];
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+find(i-1)*find(n-i);
        }
        return dp[n]=sum;
    }
    int numTrees(int n) {
        dp.resize(100,-1);
        return find(n);
    }
};