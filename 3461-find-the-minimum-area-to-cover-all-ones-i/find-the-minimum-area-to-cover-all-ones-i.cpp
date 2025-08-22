class Solution {// length=(maxcol-mincol)+1 // breadth=maxrow-minrow+1
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();


        int maxrow=-1;
        int maxcol=-1;
        int minrow=n;
        int mincol=m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxrow=max(maxrow,i);
                    minrow=min(minrow,i);

                    maxcol=max(maxcol,j);
                    mincol=min(mincol,j);
                }
            }
        }

        return (maxrow-minrow+1)*(maxcol-mincol+1);
    }
};