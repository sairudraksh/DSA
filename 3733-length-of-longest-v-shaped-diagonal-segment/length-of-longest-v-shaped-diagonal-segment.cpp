class Solution {
public:
    int n;
    int m;
    int find(int i,int j,vector<vector<int>>& grid,int direction,int turn){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==1) return 0;
        int ans1=-1;
        int ans2=-1;
        if(direction==1){// bottom right
            if(grid[i-1][j-1]==grid[i][j]) return 0;
            ans1=1+find(i+1,j+1,grid,direction,turn);
            if(turn) ans2=1+find(i+1,j-1,grid,2,0);
        }

        else if(direction==2){//bottom left
            if(grid[i-1][j+1]==grid[i][j]) return 0;
            ans1=1+find(i+1,j-1,grid,direction,turn);
            if(turn) ans2=1+find(i-1,j-1,grid,4,0);
        }

        else if(direction==3){//top right
            if(grid[i+1][j-1]==grid[i][j]) return 0;
            ans1=1+find(i-1,j+1,grid,direction,turn);
            if(turn) ans2=1+find(i+1,j+1,grid,1,0);
        }

        else if(direction==4){//top left
            if(grid[i+1][j+1]==grid[i][j]) return 0;
            ans1=1+find(i-1,j-1,grid,direction,turn);
            if(turn) ans2=1+find(i-1,j+1,grid,3,0);
        }

        return max(ans1,ans2);

    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(n==1 || m==1){
            if(grid[0][0]==1) return 1;
            return 0;
        } 
        int maximum=1;
        int onecount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    onecount++;
                    if(i+1<n && j+1<m && grid[i+1][j+1]==2){
                        maximum=max(maximum,1+find(i+1,j+1,grid,1,1));
                    }

                    if(i+1<n && j-1>=0 && grid[i+1][j-1]==2){
                        maximum=max(maximum,1+find(i+1,j-1,grid,2,1));
                    }

                    if(i-1>=0 && j+1<m && grid[i-1][j+1]==2){
                        maximum=max(maximum,1+find(i-1,j+1,grid,3,1));
                    }

                    if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==2){
                        maximum=max(maximum,1+find(i-1,j-1,grid,4,1));
                    }
                }
            }
        }
        if(onecount==0) return 0;
        return maximum;
    }
};