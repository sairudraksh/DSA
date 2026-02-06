class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        int count1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 || grid[i][j]==2){
                    count1++;
                }
            }
        }
        int count2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    count2++;
                }
            }
        }
        int ans=0;

        while(q.size()>0){
            int size=q.size();

            for(int l=0;l<size;l++){
                auto p=q.front();
                q.pop();

                int i=p.first;
                int j=p.second;
                if(i+1<n && grid[i+1][j]!=0 && grid[i+1][j]!=2){
                    grid[i+1][j]=2;
                    count2++;
                    q.push({i+1,j});
                }
                if(i-1>=0 && grid[i-1][j]!=0 && grid[i-1][j]!=2){
                    grid[i-1][j]=2;
                    count2++;
                    q.push({i-1,j});
                }
                if(j+1<m && grid[i][j+1]!=0 && grid[i][j+1]!=2){
                    grid[i][j+1]=2;
                    count2++;
                    q.push({i,j+1});
                }
                if(j-1>=0 && grid[i][j-1]!=0 && grid[i][j-1]!=2){
                    grid[i][j-1]=2;
                    count2++;
                    q.push({i,j-1});
                }
            }

            if(q.size()>0) ans++;
        }
        if(count1!=count2) return -1;
        return ans;
    }
};