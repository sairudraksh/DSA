class Solution {
public:
    int n;
    int m;
    bool isTrue(vector<vector<int>>& grid,int &t,int i,int j,vector<vector<bool>>&visited){
        if(i>=n || j>=m || i<0 || j<0 || visited[i][j]==true || grid[i][j]>t) return false;
        
        if(i==n-1 && j==m-1) return true;

        visited[i][j]=true;


        bool a=isTrue(grid,t,i+1,j,visited);
        bool b=isTrue(grid,t,i,j+1,visited);
        bool c=isTrue(grid,t,i,j-1,visited);
        bool d=isTrue(grid,t,i-1,j,visited);
        return (a || b || c || d);
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int lo=grid[0][0];
        int hi=(n*n)-1;
        int ans=0;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            vector<vector<bool>>visited;
            visited.resize(n+1,vector<bool>(m+1,false));
            if(isTrue(grid,mid,0,0,visited)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }
};