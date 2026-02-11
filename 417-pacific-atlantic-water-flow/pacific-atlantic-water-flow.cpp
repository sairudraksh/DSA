class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    int n;
    int m;
    void find(vector<vector<int>>& heights,int i,int j,vector<vector<int>>&visited,int prev){
        if(i>=m || j>=n || i<0 || j<0) return;

        if(visited[i][j] || heights[i][j]<prev){
            return;
        }

        visited[i][j]=1;

        for(auto &dir:directions){
            int l=dir[0];
            int r=dir[1];
            find(heights,i+l,j+r,visited,heights[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();

        vector<vector<int>>pasificVisited(m+1,vector<int>(n+1,0));
        
        vector<vector<int>>AtlanticVisited(m+1,vector<int>(n+1,0));


        for(int i=0;i<n;i++){
            find(heights,0,i,pasificVisited,INT_MIN);
            find(heights,m-1,i,AtlanticVisited,INT_MIN);
        }
        for(int i=0;i<m;i++){
            find(heights,i,0,pasificVisited,INT_MIN);
            find(heights,i,n-1,AtlanticVisited,INT_MIN);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pasificVisited[i][j]==1 && AtlanticVisited[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};