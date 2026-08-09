class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    void find(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&visited,int prev){
        if(i>=n || j>=m || i<0 || j<0 || visited[i][j]==1) return;

        if(grid[i][j]<prev) return; 

        visited[i][j]=1;

        for(int p=0;p<dir.size();p++){
            int first=dir[p][0];
            int second=dir[p][1];

            find(grid,i+first,j+second,visited,grid[i][j]);
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid){
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>pacificVisited;
        vector<vector<int>>atlanticVisited;
        pacificVisited.resize(n+1,vector<int>(m+1,0));
        atlanticVisited.resize(n+1,vector<int>(m+1,0));

        for(int i=0;i<m;i++){
            find(grid,0,i,pacificVisited,INT_MIN);
            find(grid,n-1,i,atlanticVisited,INT_MIN);
        }

        for(int i=0;i<n;i++){
            find(grid,i,0,pacificVisited,INT_MIN);
            find(grid,i,m-1,atlanticVisited,INT_MIN);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacificVisited[i][j]==1 && atlanticVisited[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
