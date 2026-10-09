class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find(vector<vector<int>>& piles,int i,int k){
        if(k==0) return 0;
        if(i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int skip=find(piles,i+1,k);
        int curr=0;
        int take=0;
        for(int j=0;j<piles[i].size() && j<k;j++){
            curr+=piles[i][j];
            take=max(take,curr+find(piles,i+1,k-j-1));
        }
        return dp[i][k]=max(take,skip);

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        dp.resize(n+1,vector<int>(k+1,-1));

        return find(piles,0,k);
    }
};