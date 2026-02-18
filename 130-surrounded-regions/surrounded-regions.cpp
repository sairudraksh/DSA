class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    void find(vector<vector<char>>& grid){
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            if(grid[0][i]=='O') q.push({0,i});
            if(grid[n-1][i]=='O') q.push({n-1,i});
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]=='O') q.push({i,0});
            if(grid[i][m-1]=='O') q.push({i,m-1});
        }
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            visited[i][j]=1;
            if(i+1<n && visited[i+1][j]==0 && grid[i+1][j]=='O'){
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
            if(j+1<m && visited[i][j+1]==0 && grid[i][j+1]=='O'){
                q.push({i,j+1});
                visited[i][j+1]=1;
            }
            if(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]=='O'){
                q.push({i-1,j});
                visited[i-1][j]=1;
            }
            if(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]=='O'){
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
        }
    }
    void solve(vector<vector<char>>& board){
        n=board.size();
        m=board[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        find(board);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};