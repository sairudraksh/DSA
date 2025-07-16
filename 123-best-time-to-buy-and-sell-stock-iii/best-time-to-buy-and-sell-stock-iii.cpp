class Solution {
public:
    vector<vector<vector<int>>> dp;

    int find(vector<int>&prices,int i,int k,bool flagg){
        if(i>=prices.size()) return 0;
        if(dp[i][k][flagg]!=-1) return dp[i][k][flagg];
        if(flagg==false){
            int a=0;
            int b=0;
            if(dp[i][k][flagg]!=-1) return dp[i][k][flagg];
            if(k>0){
                a=-prices[i]+find(prices,i+1,k-1,true);
            }
            b=find(prices,i+1,k,false);
            return dp[i][k][flagg]=max(a,b);
        }
        else{
            return dp[i][k][flagg]=max(prices[i]+find(prices,i+1,k,false),find(prices,i+1,k,true));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(3, vector<int>(2, -1)));
        return find(prices,0,2,false);
    }
};