class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    bool isTrue(int value,vector<vector<int>>& grid,vector<vector<int>>& dist){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }

        queue<pair<int,int>>q;
        if(dist[0][0]<value) return false;
        q.push({0,0});


        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i==n-1 && j==n-1) return true;
            if(i+1<n && visited[i+1][j]==0 && dist[i+1][j]>=value){
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
            if(j+1<n && visited[i][j+1]==0 && dist[i][j+1]>=value){
                q.push({i,j+1});
                visited[i][j+1]=1;
            }
            if(i-1>=0 && visited[i-1][j]==0 && dist[i-1][j]>=value){
                q.push({i-1,j});
                visited[i-1][j]=1;
            }
            if(j-1>=0 && visited[i][j-1]==0 && dist[i][j-1]>=value){
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,-1));


        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            if(i+1<n && dist[i+1][j]==-1){
                dist[i+1][j]=dist[i][j]+1;
                q.push({i+1,j});
            }
            if(j+1<n && dist[i][j+1]==-1){
                dist[i][j+1]=dist[i][j]+1;
                q.push({i,j+1});
            }
            if(i-1>=0 && dist[i-1][j]==-1){
                dist[i-1][j]=dist[i][j]+1;
                q.push({i-1,j});
            }
            if(j-1>=0 && dist[i][j-1]==-1){
                dist[i][j-1]=dist[i][j]+1;
                q.push({i,j-1});
            }
        }
        int lo=0;
        int hi=n;
        int ans=0;
        visited.resize(n,vector<int>(m,0));
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isTrue(mid,grid,dist)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};