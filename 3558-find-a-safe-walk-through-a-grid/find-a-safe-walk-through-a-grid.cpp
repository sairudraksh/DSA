class Solution {
public:
    int n;
    int m;
    int visited[51][51][101];
    bool find(vector<vector<int>>& grid,int &h,int t,int s){
        queue<pair<pair<int,int>,int>>q;
        if(grid[t][s]==1) h=h-1;
        if(h<=0) return false;
        q.push({{0,0},h});
        visited[0][0][h]=1;
        while(q.size()>0){
            auto l=q.front();
            q.pop();
            auto p=l.first;
            int health=l.second;
            int i=p.first;
            int j=p.second;

            if(i==n-1 && j==m-1) return true;

            if(i+1<n){
                if(grid[i+1][j]==1 && health>1 &&  visited[i+1][j][health-1]==0){
                  
                    q.push({{i+1,j},health-1});
                    visited[i+1][j][health-1]=1;
                    
                }
                else if(grid[i+1][j]==0 && visited[i+1][j][health]==0){
                    q.push({{i+1,j},health});
                    visited[i+1][j][health]=1;
                }
            }
            if(j+1<m){
                if(grid[i][j+1]==1 && health>1 && visited[i][j+1][health-1]==0){
                    
                    
                    q.push({{i,j+1},health-1});
                    visited[i][j+1][health-1]=1;
                    
                }
                else if(grid[i][j+1]==0 && visited[i][j+1][health]==0){
                    q.push({{i,j+1},health});
                    visited[i][j+1][health]=1;
                }
            }
            if(i-1>=0){
                if(grid[i-1][j]==1 && health>1 && visited[i-1][j][health-1]==0){
                   
                    
                    q.push({{i-1,j},health-1});
                    visited[i-1][j][health-1]=1;
                    
                }
                else if(grid[i-1][j]==0 && visited[i-1][j][health]==0){
                    q.push({{i-1,j},health});
                    visited[i-1][j][health]=1;
                }
            }
            if(j-1>=0){
                if(grid[i][j-1]==1 && health>1 && visited[i][j-1][health-1]==0){
                    q.push({{i,j-1},health-1});
                    visited[i][j-1][health-1]=1;
                  
                }
                else if(grid[i][j-1]==0 && visited[i][j-1][health]==0){
                    q.push({{i,j-1},health});
                    visited[i][j-1][health]=1;
                }
            }

        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n=grid.size();
        m=grid[0].size();
        memset(visited,0,sizeof(visited));
        return find(grid,health,0,0);
    }
};