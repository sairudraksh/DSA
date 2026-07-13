class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>& grid,int i,int j,int limit){
        if(i>=m && j>=m) return 0;
        else if(i>=m || j>=m) return 0;
        if(dp[i+1][j]!=-1) return dp[i+1][j];
        if(i==-1){
            return dp[i+1][j]=min(1+find(grid,-1,j+1,limit),find(grid,j,j+1,limit));
        }
        bool found=false;
        for(int l=0;l<n;l++){
            int diff=abs(grid[l][j]-grid[l][i]);
            if(diff>limit){
                found=true;
                break;
            }
        }
        if(found==true) return dp[i+1][j]=1+find(grid,i,j+1,limit);
        else return dp[i+1][j]=min(find(grid,j,j+1,limit),1+find(grid,i,j+1,limit));
        
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        n=grid.size();
        m=grid[0].size();
        dp.resize(m+1,vector<int>(m+1,-1));
        int a=find(grid,-1,0,limit);
        return (m-a);
    }
};