class Solution {
public:
    vector<int>dp;
    int find(int n){
        if(n==0) return 1;
        int maximum=1;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<=n;i++){
            maximum=max(maximum,i*find(n-i));
        }
        return dp[n]=maximum;
    }
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        int a=find(n);
        if(a==4) return a;
        if(a==n) return a-1;
        else return a;
    }
};