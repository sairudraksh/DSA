class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    void find(vector<vector<int>>& grid){
        vector<vector<int>>visited;
        visited.resize(n+1,vector<int>(m+1,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int count=1;
        while(q.size()>0){
            int size=q.size();
            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;

                for(int t=0;t<dir.size();t++){
                    int newi=i+dir[t][0];
                    int newj=j+dir[t][1];

                    if(newi<n && newj<m && newi>=0 && newj>=0 && visited[newi][newj]==0){
                        q.push({newi,newj});
                        grid[newi][newj]=count;
                        visited[newi][newj]=1;
                    }
                }
            }
            count++;
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        find(mat);
        return mat;
    }
};