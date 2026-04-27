class Solution {
public:
    vector<vector<int>>visited;
    int n;
    int m;
    vector<vector<int>>v={{1,0},{0,1},{-1,0},{0,-1}};
    int bfs(vector<vector<char>>& grid,int idx1,int idx2){
        queue<vector<int>>q;
        q.push({idx1,idx2,-1,-1});
        visited[idx1][idx2]=1;

        while(q.size()>0){
            int size=q.size();

            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();
                int i=p[0];
                int j=p[1];
                int p1=p[2];
                int p2=p[3];
                for(int t=0;t<4;t++){
                    int ni=i+v[t][0];
                    int nj=j+v[t][1];
                    if(ni>=n || ni<0 || nj>=m || nj<0) continue;
                    if(grid[ni][nj]!=grid[idx1][idx2]) continue;
                    if(visited[ni][nj]==0){
                        q.push({ni,nj,i,j});
                        visited[ni][nj]=1;
                    }
                    else if(!(ni==p1 && nj==p2)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    int a=bfs(grid,i,j);
                    if(a==true) return a;
                }
            }
        }

        return false;
    }
};