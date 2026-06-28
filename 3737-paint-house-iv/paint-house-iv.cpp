class Solution {
public:
    long long dp[100001][5][5];
    long long find(int &n,vector<vector<int>>& cost,int i,int previ,int prevj){
        int t=((n-1)-i);
        if(i>t) return 0;
        if(dp[i][previ+1][prevj+1]!=-1) return dp[i][previ+1][prevj+1];
        if(i==t){
            const auto &v1=cost[i];
            long long ans=LLONG_MAX;
            for(int l=0;l<v1.size();l++){
                if(l+1!=previ && l+1!=prevj) ans=min(ans,1LL*v1[l]+find(n,cost,i+1,l+1,l+1));
            }
            return dp[i][previ+1][prevj+1]=ans;
        }
        const auto &v1=cost[i];
        const auto &v2=cost[t];
        long long ans=LLONG_MAX;
        for(int j=0;j<v1.size();j++){
            for(int l=0;l<v2.size();l++){
                if(j==l) continue;
                else if(j+1!=previ && l+1!=prevj) ans=min(ans,1LL*v1[j]+v2[l]+find(n,cost,i+1,j+1,l+1));
            }
        }
        return dp[i][previ+1][prevj+1]=ans;

    }
    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp,-1,sizeof(dp));
        return find(n,cost,0,-1,-1);
    } 
};