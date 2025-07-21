class Solution {
public:
    vector<vector<int>>visited;
    long long find(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || i<0 || j>=m || j<0 || visited[i][j] || grid[i][j]==0){
            return 0;
        }
        visited[i][j]=1;

        long long sum=grid[i][j];
        sum+=find(grid,i+1,j);
        sum+=find(grid,i,j+1);
        sum+=find(grid,i-1,j);
        sum+=find(grid,i,j-1);

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        long long l=k;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    long long sum=find(grid,i,j);
                    if(sum%l==0) count++;
                }
            }
        }
        return count;
    }
};