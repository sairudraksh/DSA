class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int maxrow=-1;
        int maxcol=-1;

        int mincol=m;
        int minrow=n;

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