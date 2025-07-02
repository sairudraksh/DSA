class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&prices,int &fee,int i,int &n,bool flagg){
        if(i>=n) return 0;
        if(dp[i][flagg]!=-1) return dp[i][flagg];
        if(flagg==false){
            return dp[i][flagg]=max(find(prices,fee,i+1,n,true)-prices[i],find(prices,fee,i+1,n,flagg));
        }
        else{
            return dp[i][flagg]=max(prices[i]+find(prices,fee,i+1,n,false)-fee,find(prices,fee,i+1,n,flagg));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return find(prices,fee,0,n,false);
    }
};