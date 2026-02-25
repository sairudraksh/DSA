class Solution {
public:
    int n;
    vector<vector<int>>visited;
    int find(vector<vector<int>>& grid){
        queue<pair<int,int>>q;

        q.push({0,0});

        int count=0;
        visited[0][0]=1;
        while(q.size()>0){
            int size=q.size();

            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(i==n-1 && j==n-1) return count+1;
                while(i+1<n && grid[i+1][j]==0 && visited[i+1][j]==0){
                    visited[i+1][j]=1;
                    q.push({i+1,j});
                }

                while(j+1<n && grid[i][j+1]==0 && visited[i][j+1]==0){
                    visited[i][j+1]=1;
                    q.push({i,j+1});
                }

                while(i-1>=0 && grid[i-1][j]==0 && visited[i-1][j]==0){
                    visited[i-1][j]=1;
                    q.push({i-1,j});
                }

                while(j-1>=0 && grid[i][j-1]==0 && visited[i][j-1]==0){
                    visited[i][j-1]=1;
                    q.push({i,j-1});
                }

                while(i+1<n && j+1<n && grid[i+1][j+1]==0 && visited[i+1][j+1]==0){
                    visited[i+1][j+1]=1;
                    q.push({i+1,j+1});
                }

                while(i+1<n && j-1>=0 && grid[i+1][j-1]==0 && visited[i+1][j-1]==0){
                    visited[i+1][j-1]=1;
                    q.push({i+1,j-1});
                }

                while(i-1>=0 && j+1<n &&  grid[i-1][j+1]==0 && visited[i-1][j+1]==0){
                    visited[i-1][j+1]=1;
                    q.push({i-1,j+1});
                }

                while(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0 && visited[i-1][j-1]==0){
                    visited[i-1][j-1]=1;
                    q.push({i-1,j-1});
                }
            }
            count++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        n=grid.size();
        visited.resize(n+1,vector<int>(n+1,0));
        return find(grid);
    }
};