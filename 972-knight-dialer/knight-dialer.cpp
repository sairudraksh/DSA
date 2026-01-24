class Solution {
public:
    long long dp[5001][5][5];
    int mod = 1e9 + 7;
    int find(vector<vector<int>>&grid,int count,int i,int j,int &n){
        if(grid[i][j]==-1) return 0;
        if(count==n) return 1;
        if(dp[count][i][j]!=-1) return dp[count][i][j];
        long long a=0;
        long long b=0;
        long long c=0;
        long long d=0;

        long long e=0;
        long long f=0;
        long long g=0;
        long long h=0;
        if(i+2<4 && j+1<3) a=find(grid,count+1,i+2,j+1,n);
        if(i-2>=0 && j+1<3) b=find(grid,count+1,i-2,j+1,n);
        if(i-2>=0 && j-1>=0) c=find(grid,count+1,i-2,j-1,n);
        if(i+2<4 && j-1>=0) d=find(grid,count+1,i+2,j-1,n);

        if (i+1<4 && j+2<3)e = find(grid,count+1,i+1,j+2,n);
        if (i-1>=0 && j+2<3)f = find(grid,count+1,i-1,j+2,n);
        if (i+1<4 && j-2>=0)g = find(grid,count+1,i+1,j-2,n);
        if (i-1>=0 && j-2>=0)h = find(grid,count+1,i-1,j-2,n);

        return dp[count][i][j]=(a+b+c+d+e+f+g+h)%mod;
    }
    int knightDialer(int n) {
        vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        long long ans=0;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(i==3 && (j==0 || j==2)) continue;
                ans+=find(v,1,i,j,n)%mod;
            }
            
        }
        return ans%mod;
    }
};