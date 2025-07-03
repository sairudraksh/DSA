class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,int num){
        //row check
        for(int i=0;i<9;i++){
            if(board[row][i]-'0'==num) return false;
        }
        // col check
        for(int i=0;i<9;i++){
            if(board[i][col]-'0'==num) return false;
        }
        int x=(row/3)*3;
        int y=(col/3)*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j]-'0'==num) return false;
            }
        }
        return true;
    }
    bool find(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        if(col==9) return find(board,row+1,0);
        if(board[row][col]!='.'){
            return find(board,row,col+1);
        }
        for(int i=1;i<=9;i++){
            if(issafe(board,row,col,i)){
                board[row][col]='0'+i;
                bool a=find(board,row,col+1);
                if(a==true) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row=0;
        int col=0;
        find(board,row,col);

    }
};