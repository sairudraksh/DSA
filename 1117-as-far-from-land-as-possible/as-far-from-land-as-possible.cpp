class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited;
        visited.resize(n+1,vector<int>(m+1,0));
        map<pair<int,int>, int> mp;


        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                else  mp[{i,j}]++;
            }
        }
        if(mp.size()==0) return -1;
        while(q.size()>0){
            int size=q.size();

            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(grid[i][j]==0){
                    grid[i][j]==1;
                    mp.erase({i,j});
                }
                if(mp.size()==0) return count;

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
        return -1;

    }
};