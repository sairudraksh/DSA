class Solution {
public:
    bool isValid(vector<vector<char>>& grid,int row,int col,char num){
        for(int j=0;j<9;j++){
            if(j!=col && grid[row][j]==num) return false;
        }

        for(int i=0;i<9;i++){
            if(i!=row && grid[i][col]==num) return false;
        }

        int x=(row/3)*3;
        int y=(col/3)*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if((i != row || j != col) && grid[i][j] == num) return false;
            }
        }
        return true;
    }
    bool find(vector<vector<char>>&grid,int row,int col){
        if(row>=9) return true;
        if(col>=9) return find(grid,row+1,0);

        if(grid[row][col]=='.'){
            return find(grid,row,col+1);
        }
        if(!isValid(grid,row,col,grid[row][col])) return false;
        return find(grid,row,col+1);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return find(board,0,0);
    }
};