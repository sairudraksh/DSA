class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<int>&v,int i,bool run){
        if(i>=v.size()) return 0;
        if(dp[i][run]!=-1) return dp[i][run];
        if(run){
            return dp[i][run]=max(find(v,i+1,run),v[i]+find(v,i+2,false));
        }
        else{
            return dp[i][run]=max(find(v,i+1,run),find(v,i+1,true)-v[i]);
        }
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n+1,vector<int>(3,-1));
        return find(prices,0,false);
    }
};