class Solution {
public:
    int n;
    int m;
    vector<vector<int>>visited;
    bool bfs(vector<vector<int>>& grid ,int val){
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
            }
        }

        q.push({0,0});
        visited[0][0]=1;

        while(q.size()>0){
            auto p=q.front();
            q.pop();

            int i=p.first;
            int j=p.second;
            if(i==n-1 && j==m-1) return true;
            if(i+1<n && visited[i+1][j]==0){
                if(abs(grid[i+1][j]-grid[i][j])<=val){
                    

                    visited[i+1][j]=1;
                    q.push({i+1,j});
                }
            }
            if(j+1<m && visited[i][j+1]==0){
                if(abs(grid[i][j+1]-grid[i][j])<=val){
                    

                    visited[i][j+1]=1;
                    q.push({i,j+1});
                }
            }
            if(i-1>=0 && visited[i-1][j]==0){
                if(abs(grid[i-1][j]-grid[i][j])<=val){
                    

                    visited[i-1][j]=1;
                    q.push({i-1,j});
                }
            }
            if(j-1>=0 && visited[i][j-1]==0){
                if(abs(grid[i][j-1]-grid[i][j])<=val){
                    

                    visited[i][j-1]=1;
                    q.push({i,j-1});
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo=0;
        int hi=0;

        n=heights.size();
        m=heights[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hi=max(hi,heights[i][j]);
            }
        }
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(bfs(heights,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};