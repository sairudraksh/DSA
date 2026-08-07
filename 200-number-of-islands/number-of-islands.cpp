class Solution {
public:
    vector<vector<int>>visited;
    int n;
    int m;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]=='0' || visited[i][j]==1) return;
        visited[i][j]=1;

        dfs(grid,i+1,j),dfs(grid,i,j+1),dfs(grid,i-1,j),dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    result+=1;
                    dfs(grid,i,j);
                }
            }
        }
        return result;
    }
};