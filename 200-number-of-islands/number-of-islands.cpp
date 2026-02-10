class Solution {
public:
    vector<vector<int>>visited;
    int n;
    int m;
    int find(vector<vector<char>>& grid,int l,int r){

        queue<pair<int,int>>q;
        q.push({l,r});
        visited[l][r]=1;

        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i+1<n && grid[i+1][j]!='0' && visited[i+1][j]==0){
                q.push({i+1,j});
                visited[i+1][j]=1;
            }

            if(i-1>=0 && grid[i-1][j]!='0' && visited[i-1][j]==0){
                q.push({i-1,j});
                visited[i-1][j]=1;
            }

            if(j+1<m && grid[i][j+1]!='0' && visited[i][j+1]==0){
                q.push({i,j+1});
                visited[i][j+1]=1;
            }

            if(j-1>=0 && grid[i][j-1]!='0' && visited[i][j-1]==0){
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();

        visited.resize(n+1,vector<int>(m+1,0));
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    int a=find(grid,i,j);
                    count+=a;
                }
            }
        }
        return count;
    }
};