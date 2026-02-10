class Solution {
public:
    int n;
    int m;
    void find(vector<vector<int>>& grid,int l,int t,int &color){
        int val=grid[l][t];
        vector<vector<int>>visited;
        visited.resize(n+1,vector<int>(m+1,0));
        queue<pair<int,int>>q;
        q.push({l,t});
        visited[l][t]=1;
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            grid[i][j]=color;
            if(i+1<n && grid[i+1][j]==val && visited[i+1][j]==0){
                visited[i+1][j]=1;
                q.push({i+1,j});
            }
            if(j+1<m && grid[i][j+1]==val && visited[i][j+1]==0){
                visited[i][j+1]=1;
                q.push({i,j+1});
            }
            if(i-1>=0 && grid[i-1][j]==val && visited[i-1][j]==0){
                visited[i-1][j]=1;
                q.push({i-1,j});
            }
            if(j-1>=0 && grid[i][j-1]==val && visited[i][j-1]==0){
                visited[i][j-1]=1;
                q.push({i,j-1});
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();
        find(image,sr,sc,color);
        return image;
    }
};