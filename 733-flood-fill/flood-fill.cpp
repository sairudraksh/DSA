class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int num=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<int>>visited;
        int n=image.size();
        int m=image[0].size();
        visited.resize(n+1,vector<int>(m+1,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        while(q.size()>0){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            while(i+1<n && visited[i+1][j]==0 && image[i+1][j]==num){
                image[i+1][j]=color;
                visited[i+1][j]=1;
                q.push({i+1,j});
            }
            while(j+1<m && visited[i][j+1]==0 && image[i][j+1]==num){
                image[i][j+1]=color;
                visited[i][j+1]=1;
                q.push({i,j+1});
            }
            while(i-1>=0 && visited[i-1][j]==0 && image[i-1][j]==num){
                image[i-1][j]=color;
                visited[i-1][j]=1;
                q.push({i-1,j});
            }
            while(j-1>=0 && visited[i][j-1]==0 && image[i][j-1]==num){
                image[i][j-1]=color;
                visited[i][j-1]=1;
                q.push({i,j-1});
            }
        }
        return image;
    }
};