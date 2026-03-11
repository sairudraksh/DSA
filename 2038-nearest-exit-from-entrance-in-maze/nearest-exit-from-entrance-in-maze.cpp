class Solution {
public:
    int n;
    int m;
    int find(vector<vector<char>>& maze,int row,int col){
        queue<pair<int,int>>q;
        int count=0;

        q.push({row,col});
        vector<vector<int>>visited;
        visited.resize(n+1,vector<int>(m+1,0));
        visited[row][col]=1;

        while(q.size()>0){
            int size=q.size();
            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(i>=n || i<0 || j>=m || j<0 && !(i==row && j==col)) return count;

                if(i+1<n && visited[i+1][j]==0 && maze[i+1][j]!='+'){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                }
                else if(i+1>=n && !(i==row && j==col)) return count;
                if(j+1<m && visited[i][j+1]==0 && maze[i][j+1]!='+'){
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                }
                else if(j+1>=m && !(i==row && j==col)) return count;
                if(i-1>=0 && visited[i-1][j]==0 && maze[i-1][j]!='+'){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                }
                else if(i-1<0 && !(i==row && j==col)) return count;
               if(j-1>=0 && visited[i][j-1]==0 && maze[i][j-1]!='+'){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                }
                else if(j-1<0 && !(i==row && j==col)) return count;
            }
            count++;
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        n=grid.size();
        m=grid[0].size();
        return find(grid,entrance[0],entrance[1]);
    }
};