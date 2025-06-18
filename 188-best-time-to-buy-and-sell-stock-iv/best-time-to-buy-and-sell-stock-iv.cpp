class Solution {
public:
    int dp[1005][105][2];
    int find(vector<int>&prices,int idx,int k,bool on){
        if(idx>=prices.size()) return dp[idx][k][on]=0;
        if(dp[idx][k][on]!=-1) return dp[idx][k][on];
        if(on==true){
            return dp[idx][k][on]=max(prices[idx]+find(prices,idx+1,k,false),find(prices,idx+1,k,true));
        }
        else{
            return dp[idx][k][on]=max((k<1?INT_MIN:-prices[idx]+find(prices,idx+1,k-1,true)),find(prices,idx+1,k,false));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        bool on=false;
        int idx=0;
        memset(dp,-1,sizeof dp);
        return find(prices,idx,k,on);
    }
};