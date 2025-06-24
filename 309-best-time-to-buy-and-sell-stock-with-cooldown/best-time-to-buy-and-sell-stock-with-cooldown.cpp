class Solution {
public:
    vector<vector<long long>>dp;
    int find(vector<int>&prices,int i,bool flagg,int &n){
        if(i>=n) return 0;
        if(dp[i][flagg]!=-1) return dp[i][flagg];
        if(i==n-1 && flagg==true) return dp[i][flagg]=prices[i];
        if(flagg==false){
            return dp[i][flagg]=max(-prices[i]+find(prices,i+1,true,n),find(prices,i+1,false,n));
        }
        return dp[i][flagg]=max(prices[i]+find(prices,i+2,false,n),find(prices,i+1,true,n));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        dp.resize(5001,vector<long long>(2,-1));
        bool flagg=false;
        int i=0;
        return find(prices,i,flagg,n);
    }
};