class Solution {
public:
    long long n;
    long long m;
    long long dp[70][70][70];
    long long f(long long i,long long j,long long x,long long y,vector<vector<int>>& grid){
        if(i>=n || j>=m || x>=n || y>=m || i<0 || j<0 || x<0 || y<0) return LLONG_MIN;
        if((i==n-1 && x!=n-1) || (i!=n-1 && x==n-1)){
            return LLONG_MIN;
        }
        if(i==n-1 && x==n-1){
            if(j==y) return grid[i][j];
            else return grid[i][j]+grid[x][y];
        }
        if(dp[j][x][y]!=-1) return dp[j][x][y];
        long long result=LLONG_MIN;
        result=max(result,f(i+1,j-1,x+1,y-1,grid));
        result=max(result,f(i+1,j-1,x+1,y,grid));
        result=max(result,f(i+1,j-1,x+1,y+1,grid));

        result=max(result,f(i+1,j,x+1,y,grid));
        result=max(result,f(i+1,j,x+1,y-1,grid));
        result=max(result,f(i+1,j,x+1,y+1,grid));

        result=max(result,f(i+1,j+1,x+1,y,grid));
        result=max(result,f(i+1,j+1,x+1,y-1,grid));
        result=max(result,f(i+1,j+1,x+1,y+1,grid));

        if(result==LLONG_MIN) return dp[j][x][y]=LLONG_MIN;
        result+=grid[i][j];
        result+=grid[x][y];

        if(i==x && j==y) result-=grid[x][y];

        return dp[j][x][y]=result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof dp);
        long long a=f(0,0,0,m-1,grid);
        if(a==LLONG_MIN) return 0;
        return a;
    }
};