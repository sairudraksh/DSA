class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    int bfs(vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        int goodOranges=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                
            }
        }
        int count=0;
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

                    if(newi<n && newj<m && newi>=0 && newj>=0 && grid[newi][newj]==1){
                        q.push({newi,newj});
                        grid[newi][newj]=2;
                      
                    }
                }
            }

            if(size>0) count++;
        }  
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int a=bfs(grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        if(a==0) return a;
        return a-1;
    }
};