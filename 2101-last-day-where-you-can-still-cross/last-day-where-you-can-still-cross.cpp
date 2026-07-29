class Solution {
public:
    bool find(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;

        vector<vector<int>>visited;
        visited.resize(n+1,vector<int>(m+1,0));

        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                q.push({0,i});
                visited[0][i]=1;
            }
        }
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i==n-1) return true;
            if(i+1<n && visited[i+1][j]==0 && grid[i+1][j]==0){
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
            if(j+1<m && visited[i][j+1]==0 && grid[i][j+1]==0){
                q.push({i,j+1});
                visited[i][j+1]=1;
            }
            if(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]==0){
                q.push({i-1,j});
                visited[i-1][j]=1;
            }
            if(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]==0){
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int lo=0;
        int hi=n-1;
        vector<vector<int>>v;
        v.resize(row,vector<int>(col,0));
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            for(int i=lo;i<=mid;i++){
                int idx1=grid[i][0]-1;
                int idx2=grid[i][1]-1;

                v[idx1][idx2]=1;
            }

            bool a=find(v);

            if(a){
                lo=mid+1;
                ans=mid+1;
            }
            else hi=mid-1;

            for(int i=lo;i<=mid;i++){
                int idx1=grid[i][0]-1;
                int idx2=grid[i][1]-1;

                v[idx1][idx2]=0;
            }
        }
        return ans;
    }
};