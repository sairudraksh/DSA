class Solution {
public:
    vector<vector<int>> rotatedList(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rotatedGrid(n, vector<int>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rotatedGrid[j][m-i-1] = grid[i][j];
            }
        }

        return rotatedGrid;
    }
    int find(int rowst,int rowend,int colst,int colend,vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int maxrow=-1;
        int maxcol=-1;
        int minrow=m;
        int mincol=n;
        
        for(int i=rowst;i<rowend;i++){
            for(int j=colst;j<colend;j++){
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
    int findi(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int minimum=INT_MAX;
        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                int top=find(0,row,0,n,grid);
                int left=find(row,m,0,col,grid);
                int right=find(row,m,col,n,grid);
                minimum=min(minimum,top+left+right);
            }
        }

        for(int row=1;row<m;row++){
            for(int col=1;col<n;col++){
                int topleft=find(0,row,0,col,grid);
                int topright=find(0,row,col,n,grid);
                int bottom=find(row,m,0,n,grid);
                minimum=min(minimum,topleft+topright+bottom);
            }
        }

        for(int split1=1;split1<m;split1++){
            for(int split2=split1+1;split2<m;split2++){
                int top=find(0,split1,0,n,grid);
                int left=find(split1,split2,0,n,grid);
                int right=find(split2,m,0,n,grid);
                minimum=min(minimum,top+left+right);
            }
        }
        return minimum;
    }
    int minimumSum(vector<vector<int>>& grid) {

        int a=findi(grid);
        vector<vector<int>>rotated=rotatedList(grid);

        int b=findi(rotated);
        return min(a,b);
    }
};