class Solution {
public:
    int n;
    vector<int>frees;
    int mini;
    int dp[1000][1501];
    int find(vector<vector<int>>& items,int i,int budget){
        if(i>=n) return budget/mini;
        if(dp[i][budget]!=-1) return dp[i][budget];
        int skip=find(items,i+1,budget);
        int take=0;
        if(items[i][1]<=budget){
            take=frees[i]+find(items,i+1,budget-items[i][1]);
        }
        return dp[i][budget]=max(take,skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        frees.resize(n,0);
        mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,items[i][1]);
            for(int j=0;j<n;j++){
                if(items[j][0]%items[i][0]==0) frees[i]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return find(items,0,budget);
    }
};