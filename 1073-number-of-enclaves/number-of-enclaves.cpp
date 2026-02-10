class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>& grid,int l,int r){

        queue<pair<int,int>>q;
        queue<pair<int,int>>q2;
        q.push({l,r});

        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        vector<vector<int>>visited;
        visited.resize(n+1,vector<int>(m+1,0));
        visited[l][r]=1;
        int ans=1;
        while(q.size()>0){
            auto p=q.front();
            q2.push(p);
            q.pop();

            int i=p.first;
            int j=p.second;

            if(i+1>=n || i-1<0 || j+1>=m || j-1<0){
                ans=0;
            }
            if(i+1<n && (dp[i+1][j]==0 || dp[i+1][j]==1)){
                ans=dp[i+1][j];
                break;
            }
            if(i-1 >=0 && (dp[i-1][j]==0 || dp[i-1][j]==1)){
                ans=dp[i-1][j];
                break;
            }
            if(j-1>=0 && (dp[i][j-1]==0 || dp[i][j-1]==1)){
                ans=dp[i][j-1];
                break;
            }
            if(j+1<m && (dp[i][j+1]==0 || dp[i][j+1]==1)){
                ans=dp[i][j+1];
                break;
            }

            if( i+1<n &&  grid[i+1][j]!=0 && visited[i+1][j]==0){
                if(dp[i+1][j]!=-1){
                    ans=dp[i+1][j];
                    break;
                }
                visited[i+1][j]=1;
                q.push({i+1,j});
            }
            if( i-1>=0 && grid[i-1][j]!=0 && visited[i-1][j]==0){
                if(dp[i-1][j]!=-1){
                    ans=dp[i-1][j];
                    break;
                }
                visited[i-1][j]=1;
                q.push({i-1,j});
            }
            if(j-1>=0 && grid[i][j-1]!=0 && visited[i][j-1]==0){
                if(dp[i][j-1]!=-1){
                    ans=dp[i][j-1];
                    break;
                }
                visited[i][j-1]=1;

                q.push({i,j-1});
            }
            if(j+1<m && grid[i][j+1]!=0 && visited[i][j+1]==0){
                if(dp[i][j+1]!=-1){
                    ans=dp[i][j+1];
                    break;
                }
                visited[i][j+1]=1;
                q.push({i,j+1});
            }
        }
        
        while(q2.size()>0){
            auto p=q2.front();
            q2.pop();

            int i=p.first;
            int j=p.second;

            if(ans==1) dp[i][j]=1;
            else dp[i][j]=0;
        } 
        
        return dp[l][r]=ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=-1){
                    count+=dp[i][j];
                }
                else{
                    if(grid[i][j]==1){
                        int a=find(grid,i,j);
                        count+=a;
                    }
                }
            }
        }
        return count;
    }
};