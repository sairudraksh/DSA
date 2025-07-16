class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&arr,int i,bool flagg){
        if(i>=arr.size()) return 0;
        if(dp[i][flagg]!=-1) return dp[i][flagg];
        if(flagg==false){
            return dp[i][flagg]=max(-arr[i]+find(arr,i+1,true),find(arr,i+1,false));
        }
        return dp[i][flagg]=max(arr[i]+find(arr,i+1,false),find(arr,i+1,true));
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1,vector<int>(2,-1));
        return find(prices,0,false);
    }
};