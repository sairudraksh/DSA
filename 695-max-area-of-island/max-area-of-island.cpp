class Solution {
public:
    vector<vector<int>>visited;
    int n;
    int m;
    int find(vector<vector<int>>& grid,int l,int r){
        queue<pair<int,int>>q;

        q.push({l,r});
        int count=1;
        while(q.size()>0){
            auto p=q.front();
            q.pop();

            int i=p.first;
            int j=p.second;

            visited[i][j]=1;

            if(i+1<n && visited[i+1][j]==0 && grid[i+1][j]==1){
                q.push({i+1,j});
                visited[i+1][j]=1;
                count++;
            }

            if(j+1<m && visited[i][j+1]==0 && grid[i][j+1]==1){
                q.push({i,j+1});
                visited[i][j+1]=1;
                count++;
            }

            if(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]==1){
                q.push({i-1,j});
                visited[i-1][j]=1;
                count++;
            }

            if(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]==1){
                q.push({i,j-1});
                visited[i][j-1]=1;
                count++;
            }
            
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    int a=find(grid,i,j);
                    count=max(a,count);
                }
            }
        }
        return count;
    }
};