class Solution {
public:
    bool isvalid(vector<vector<char>>& grid,int row,int col,int num){
        for(int j=0;j<9;j++){
            if(grid[row][j]-'0'==num) return false;
        }

        for(int i=0;i<9;i++){
            if(grid[i][col]-'0'==num) return false;
        }

        int x=(row/3)*3;
        int y=(col/3)*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(grid[i][j]-'0'==num) return false;
            }
        }
        return true;
    }
    bool find(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        if(col==9) return find(board,row+1,0);

        if(board[row][col]!='.') return find(board,row,col+1);

        for(int i=1;i<=9;i++){
            if(isvalid(board,row,col,i)){
                board[row][col]='0'+i;
                bool a=find(board,row,col+1);
                if(a==true) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        find(board,0,0);
    }
};