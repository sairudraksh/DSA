class Solution {
public:
    void find(vector<vector<int>>& grid,int row,int col,int color){
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited;
        visited.resize(n+1,vector<int>(m+1,0));
        int num=grid[row][col];
        visited[row][col]=1;
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            bool found1=false;
            bool found2=false;
            bool found3=false;
            bool found4=false;

            if(i+1<n && visited[i+1][j]==0 && grid[i+1][j]==num){
                q.push({i+1,j});
                visited[i+1][j]=1;
                found1=true;
            }
            if(j+1<m && visited[i][j+1]==0 && grid[i][j+1]==num){
                q.push({i,j+1});
                visited[i][j+1]=1;
                found2=true;
            }
            if(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]==num){
                q.push({i-1,j});
                visited[i-1][j]=1;
                found3=true;
            }
            if(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]==num){
                q.push({i,j-1});
                visited[i][j-1]=1;
                found4=true;
            }
            if(i+1<n && visited[i+1][j]==1) found1=true;
            if(j+1<m && visited[i][j+1]==1) found2=true;
            if(i-1>=0 && visited[i-1][j]==1) found3=true;
            if(j-1>=0 && visited[i][j-1]==1) found4=true;
            if(found1==false || found2==false || found3==false || found4==false) grid[i][j]=color;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        find(grid,row,col,color);
        return grid;
    }
};