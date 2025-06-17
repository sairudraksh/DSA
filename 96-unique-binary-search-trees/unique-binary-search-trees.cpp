class Solution {
public:
    vector<int>dp;
    int find(int n){
        if(n==1 || n==0) return dp[n]=1;
        if(n==2) return dp[n]=2;
        if(dp[n]!=-1) return dp[n];
        int sum=0;
        for(int k=1;k<=n;k++){
            sum=sum+find(k-1)*find(n-k);
        }
        return dp[n]=sum;
    }
    int numTrees(int n) {
        dp.resize(100,-1);
        return find(n);
    }
};