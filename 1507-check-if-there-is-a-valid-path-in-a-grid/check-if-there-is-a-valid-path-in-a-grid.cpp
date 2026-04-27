class Solution {
public:
    vector<vector<int>>visited;
    int n;
    int m;
    bool find(vector<vector<int>>& grid,int idx1,int idx2){
        queue<pair<int,int>>q;
        q.push({idx1,idx2});

        visited[idx1][idx2]=1;
        while(q.size()>0){
            auto p=q.front();
            q.pop();

            int i=p.first;
            int j=p.second;
            if(i==n-1 && j==m-1) return true;
            int num=grid[i][j];

            if(num==1){
                if(j-1>=0 && visited[i][j-1]==0 && (grid[i][j-1]==4 || grid[i][j-1]==6  || grid[i][j-1]==1)){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
                if(j+1<m && visited[i][j+1]==0 && (grid[i][j+1]==3 || grid[i][j+1]==5 || grid[i][j+1]==1)){
                    q.push({i,j+1});
                    visited[i][j+1]=1; 
                }
            }

            if(num==2){
                if(i-1>=0 && visited[i-1][j]==0 && (grid[i-1][j]==3 || grid[i-1][j]==4 || grid[i-1][j]==2)){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                if(i+1<n && visited[i+1][j]==0 && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6)){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
            }
            if(num==3){
                if(j-1>=0 && visited[i][j-1]==0 && (grid[i][j-1]==4 || grid[i][j-1]==6  || grid[i][j-1]==1)){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
                if(i+1<n && visited[i+1][j]==0 && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6)){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
            }
            if(num==4){
                if(j+1<m && visited[i][j+1]==0 && (grid[i][j+1]==3 || grid[i][j+1]==5 || grid[i][j+1]==1)){
                    q.push({i,j+1});
                    visited[i][j+1]=1; 
                }
                if(i+1<n && visited[i+1][j]==0 && (grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6)){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
            }
            if(num==5){
                if(i-1>=0 && visited[i-1][j]==0 && (grid[i-1][j]==3 || grid[i-1][j]==4 || grid[i-1][j]==2)){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                if(j-1>=0 && visited[i][j-1]==0 && (grid[i][j-1]==4 || grid[i][j-1]==6  || grid[i][j-1]==1)){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
            }
            if(num==6){
                if(i-1>=0 && visited[i-1][j]==0 && (grid[i-1][j]==3 || grid[i-1][j]==4 || grid[i-1][j]==2)){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                if(j+1<m && visited[i][j+1]==0 && (grid[i][j+1]==3 || grid[i][j+1]==5 || grid[i][j+1]==1)){
                    q.push({i,j+1});
                    visited[i][j+1]=1; 
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n+1,vector<int>(m+1,0));

        return find(grid,0,0);
    }
};