class Solution {
public:
    int n;
    int m;
    int find(vector<vector<int>>& grid,int i,int j,int direction,bool hasTurned){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==1) return 0;


        int maximum=0;
        if(direction==1){
            int prev=grid[i-1][j-1];
            if(prev==1 && grid[i][j]!=2) return 0;
            if(grid[i][j]==prev) return 0;
            int a=1+find(grid,i+1,j+1,direction,hasTurned);
            int b=0;
            if(!hasTurned) b=1+find(grid,i+1,j-1,2,true);
            maximum=max(a,b);
        }

        if(direction==2){
            int prev=grid[i-1][j+1];
            if(prev==1 && grid[i][j]!=2) return 0;
            if(grid[i][j]==prev) return 0;
            int a=1+find(grid,i+1,j-1,direction,hasTurned);
            int b=0;
            if(!hasTurned) b=1+find(grid,i-1,j-1,3,true);
            maximum=max(a,b);
        }

        if(direction==3){
            int prev=grid[i+1][j+1];
            if(prev==1 && grid[i][j]!=2) return 0;
            if(grid[i][j]==prev) return 0;
            int a=1+find(grid,i-1,j-1,direction,hasTurned);
            int b=0;
            if(!hasTurned) b=1+find(grid,i-1,j+1,4,true);
            maximum=max(a,b);
        }

        if(direction==4){
            int prev=grid[i+1][j-1];
            if(prev==1 && grid[i][j]!=2) return 0;
            if(grid[i][j]==prev) return 0;
            int a=1+find(grid,i-1,j+1,direction,hasTurned);
            int b=0;
            if(!hasTurned) b=1+find(grid,i+1,j+1,1,true);
            maximum=max(a,b);
        }
        return maximum;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        int maximum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                
                    maximum=max(maximum,1+find(grid,i+1,j+1,1,false));

                    maximum=max(maximum,1+find(grid,i+1,j-1,2,false));

                    maximum=max(maximum,1+find(grid,i-1,j-1,3,false));

                    maximum=max(maximum,1+find(grid,i-1,j+1,4,false));
                }       
            }
        }
        return maximum;
    }
};