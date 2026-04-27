class Solution {
public:
    int m;
    int dp[1001][4];
    long long mod=1e9+7;
    int find(vector<vector<int>>&grid,int pos,int i,int j){
        if(j>=m) return 1;
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        if(dp[j][pos]!=-1) return dp[j][pos];
        if(pos==0 || pos==1){
            a=find(grid,1,0,j+1);
            if(j+2<=m){
                b=find(grid,1,0,j+2);
                c=find(grid,3,0,j+1);
                d=find(grid,2,1,j+1);
            }
            return dp[j][pos]=(a%mod+b%mod+c%mod+d%mod)%mod;
        }
        else if(pos==2){
            if(j+2<=m){
                a=find(grid,1,0,j+2);
                b=find(grid,3,0,j+1);
            }
            return dp[j][pos]=(a%mod+b%mod)%mod;
        }
        else{
            if(j+2<=m){
                a=find(grid,1,0,j+2);
                b=find(grid,2,0,j+1);
            }
            return dp[j][pos]=(a%mod+b%mod)%mod;
        }
    }
    int numTilings(int n) {
        m=n;
        vector<vector<int>>grid;
        memset(dp,-1,sizeof(dp));
        grid.resize(2,vector<int>(n,0));
        return find(grid,0,0,0)%mod;
    }
};