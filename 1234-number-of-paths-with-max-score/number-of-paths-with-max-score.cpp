class Solution {
public:
    vector<vector<int>>dp1;
    vector<vector<vector<int>>> dp2;
    int mod=1e9+7;
    int n;
    int m;
    int findCount(int i,int j,int target,vector<string>& grid){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='X'){
            return 0;
        }
        if(i==0 && j==0){
            if(target==0) return 1;
            return 0;
        }
        if(dp2[i][j][target]!=-1) return dp2[i][j][target];
        int num=0;
        if(isdigit(grid[i][j])) num=grid[i][j]-'0';
        
        int a=findCount(i-1,j,target-num,grid);
        int b=findCount(i,j-1,target-num,grid);
        int c=findCount(i-1,j-1,target-num,grid);
        return dp2[i][j][target]=(a+b+c)%mod;
    }
    int findSum(int i,int j,vector<string>& grid){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='X'){
            return INT_MIN;
        }
        if(i==0 && j==0) return 0;
        if(dp1[i][j]!=-1) return dp1[i][j];
        int a=findSum(i-1,j,grid);
        int b=findSum(i,j-1,grid);
        int c=findSum(i-1,j-1,grid);
        int num=0;
        if(isdigit(grid[i][j])) num=grid[i][j]-'0';
        
        if(a!=INT_MIN) a+=num;
        if(b!=INT_MIN) b+=num;
        if(c!=INT_MIN) c+=num;
        return dp1[i][j]=max({a,b,c})%mod;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();
        dp1.resize(n+1,vector<int>(m+1,-1));
        int sum=findSum(n-1,m-1,board)%mod;
        if(sum<0) return {0,0};
        dp2.resize(n, vector<vector<int>>(m, vector<int>(sum + 1, -1)));
        int count=findCount(n-1,m-1,sum,board)%mod;
        return {sum,count};
    }
};