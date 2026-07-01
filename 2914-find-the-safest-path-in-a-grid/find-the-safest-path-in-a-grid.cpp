class Solution {
public:
    vector<vector<int>>visited;
    vector<vector<int>>dist;
    int n;
    bool canGo(vector<vector<int>>&grid,int val){
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        if(dist[0][0] < val) return false;
        q.push({0,0});
        visited[0][0]=1;

        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            if(i==n-1 && j==n-1) return true;

            if(i+1<n && visited[i+1][j]==0 && dist[i+1][j]>=val){
                visited[i+1][j]=1;
                q.push({i+1,j});
            }

            if(j+1<n && visited[i][j+1]==0 && dist[i][j+1]>=val){
                visited[i][j+1]=1;
                q.push({i,j+1});
            }

            if(i-1>=0 && visited[i-1][j]==0 && dist[i-1][j]>=val){
                visited[i-1][j]=1;
                q.push({i-1,j});
            }

            if(j-1>=0 && visited[i][j-1]==0 && dist[i][j-1]>=val){
                visited[i][j-1]=1;
                q.push({i,j-1});
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        dist.resize(n+1,vector<int>(n+1,-1));
        visited.resize(n+1,vector<int>(n+1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
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
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(canGo(grid,mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};