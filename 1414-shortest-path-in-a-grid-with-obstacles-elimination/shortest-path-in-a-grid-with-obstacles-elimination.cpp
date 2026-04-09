class Solution {
public:
    int n;
    int m;
    int bfs(int l,int c,int x,vector<vector<int>>& grid){
        queue<vector<int>>q;
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(x + 1, 0)));
        q.push({0,0,x,0});
        int maxcount=INT_MIN;
        visited[0][0][x]=1;
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p[0];
            int j=p[1];
            int k=p[2];
            int count=p[3];

            if(i==n-1 && j==m-1){
                if(grid[i][j]==1 && k<=0) continue;
                return count;
            }
            

            if(i+1<n){
                if(grid[i+1][j]==1){
                    if(k>0&& visited[i+1][j][k-1]==0){
                        q.push({i+1,j,k-1,count+1});
                        visited[i+1][j][k-1]=1;
                    }
                }
                else if(visited[i+1][j][k]==0){
                    q.push({i+1,j,k,count+1});
                    visited[i+1][j][k]=1;
                }
            }
            if(j+1<m ){
                if(grid[i][j+1]==1){
                    if(k>0 && visited[i][j+1][k-1]==0){
                        q.push({i,j+1,k-1,count+1});
                        visited[i][j+1][k-1]=1;
                    }
                }
                else if(visited[i][j+1][k]==0){
                    q.push({i,j+1,k,count+1});
                    visited[i][j+1][k]=1;
                }
            }
            if(i-1>=0){
                if(grid[i-1][j]==1){
                    if(k>0&& visited[i-1][j][k-1]==0){
                        q.push({i-1,j,k-1,count+1});
                        visited[i-1][j][k-1]=1;
                    }
                }
                else if(visited[i-1][j][k]==0){
                    q.push({i-1,j,k,count+1});
                    visited[i-1][j][k]=1;
                }
            }
            if(j-1>=0){
                if(grid[i][j-1]==1){
                    if(k>0&& visited[i][j-1][k-1]==0){
                        q.push({i,j-1,k-1,count+1});
                        visited[i][j-1][k-1]=1;
                    }
                }
                else if(visited[i][j-1][k]==0){
                    q.push({i,j-1,k,count+1});
                    visited[i][j-1][k]=1;
                }
            }
        }
        return maxcount;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int a=bfs(0,0,k,grid);
        if(a==INT_MIN) return -1;
        return a;
    }
};