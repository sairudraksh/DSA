class Solution {
public:
    vector<vector<int>>visited;
    int n;
    int m;
    int bfs(vector<vector<int>>& grid,int l,int t){
        queue<pair<int,int>>q;
        q.push({0,0});
        visited.resize(n+1,vector<int>(m+1,INT_MAX));
        int mincount=INT_MAX;
        visited[0][0]=0;
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            if(i==n-1 && j==m-1){
                mincount=min(mincount,visited[i][j]);
                continue;
            }

            if(i+1<n){
                if(grid[i+1][j]==1){
                    int num=visited[i][j]+1;
                    if(num<visited[i+1][j]){
                        q.push({i+1,j});
                        visited[i+1][j]=num;
                    }
                }
                else if(visited[i+1][j]>visited[i][j]){
                    visited[i+1][j]=visited[i][j];
                    q.push({i+1,j});
                }
            }
            if(j+1<m){
                if(grid[i][j+1]==1){
                    int num=visited[i][j]+1;
                    if(num<visited[i][j+1]){
                        q.push({i,j+1});
                        visited[i][j+1]=num;
                    }
                }
                else if(visited[i][j+1]>visited[i][j]){
                    visited[i][j+1]=visited[i][j];
                    q.push({i,j+1});
                }
            }
            if(i-1>=0){
                if(grid[i-1][j]==1){
                    int num=visited[i][j]+1;
                    if(num<visited[i-1][j]){
                        q.push({i-1,j});
                        visited[i-1][j]=num;
                    }
                }
                else if(visited[i-1][j]>visited[i][j]){
                    visited[i-1][j]=visited[i][j];
                    q.push({i-1,j});
                }
            }
            if(j-1>=0){
                if(grid[i][j-1]==1){
                    int num=visited[i][j]+1;
                    if(num<visited[i][j-1]){
                        q.push({i,j-1});
                        visited[i][j-1]=num;
                    }
                }
                else if(visited[i][j-1]>visited[i][j]){
                    visited[i][j-1]=visited[i][j];
                    q.push({i,j-1});
                }
            }

        }

        return mincount;

    }
    int minimumObstacles(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        return bfs(grid,0,0);
    }
};