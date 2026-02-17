class Solution {
public:
    int n;
    int m;
    vector<vector<int>>ans;
    vector<vector<int>>visited;
    void find(vector<vector<int>>&grid){
        visited.assign(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        ans.assign(n,vector<int>(m,0));
        while(q.size()>0){
            int size=q.size();
            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();

                int i=p.first;
                int j=p.second;
                if(grid[i][j]==0){
                    ans[i][j]=count;
                }
                visited[i][j]=1;
                if(i+1<n && visited[i+1][j]==0){
                    q.push({i+1,j});
                    visited[i+1][j]=1;
                    
                }
                if(j+1<m && visited[i][j+1]==0){
                    q.push({i,j+1});
                    visited[i][j+1]=1;
                    
                }
                if(i-1>=0 && visited[i-1][j]==0){
                    q.push({i-1,j});
                    visited[i-1][j]=1;
                
                }
                if(j-1>=0 && visited[i][j-1]==0){
                    q.push({i,j-1});
                    visited[i][j-1]=1;
                
                }
            }
            count++;
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        find(grid);
        return ans;
    }
};