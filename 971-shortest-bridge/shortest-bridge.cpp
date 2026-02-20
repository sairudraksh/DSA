class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    int find(vector<vector<int>>& grid,queue<pair<int,int>>&q){
        int count=0;
        while(q.size()>0){
            int size=q.size();

            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;

                while(i+1<n && visited[i+1][j]==0){
                    if(grid[i+1][j]==1) return count;
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
                while(j+1<m && visited[i][j+1]==0){
                    if(grid[i][j+1]==1) return count;
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                }
                while(i-1>=0 && visited[i-1][j]==0){
                    if(grid[i-1][j]==1) return count;
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                while(j-1>=0 && visited[i][j-1]==0){
                    if(grid[i][j-1]==1) return count;
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
            }
            count++;
        }
        return count;
    }

    void formQueue(vector<vector<int>>& grid,int idx1,int idx2,queue<pair<int,int>>&q2){
        queue<pair<int,int>>q;
        q.push({idx1,idx2});
        q2.push({idx1,idx2});
        visited[idx1][idx2]=1;
        while(q.size()>0){
            int size=q.size();

            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            while(i+1<n && visited[i+1][j]==0 && grid[i+1][j]==1){
                q2.push({i+1,j});
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
            while(j+1<m && visited[i][j+1]==0 && grid[i][j+1]==1){
                q2.push({i,j+1});
                q.push({i,j+1});
                visited[i][j+1]=1;
            }
            while(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]==1){
                q2.push({i-1,j});
                q.push({i-1,j});
                visited[i-1][j]=1;
            }
            while(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]==1){
                q2.push({i,j-1});
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
        }

    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){

                    queue<pair<int,int>>q;
                    formQueue(grid,i,j,q);
                    return find(grid,q);
                }
            }
        }
        return 0;
    }
};