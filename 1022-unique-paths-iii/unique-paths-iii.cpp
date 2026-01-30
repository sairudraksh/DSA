class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    int find(vector<vector<int>>&grid,int i,int j,int count,int &target){
        if(i>=n || j>=m || i<0 || j<0) return 0;
        if(grid[i][j]==-1) return 0;
        if(grid[i][j]==2){
            if(count==target) return 1;
            return 0;
        }
        if(visited[i][j]!=0) return 0;
        visited[i][j]=1;
        if(grid[i][j]==0) count++;
        int a=find(grid,i+1,j,count,target)+find(grid,i-1,j,count,target)+find(grid,i,j+1,count,target)+find(grid,i,j-1,count,target);
        visited[i][j]=0;
        return a;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        int idx1=-1;
        int idx2=-1;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    idx1=i;
                    idx2=j;
                }
                else if(grid[i][j]==0) count++;
            }
        }
        return find(grid,idx1,idx2,0,count);
    }
};