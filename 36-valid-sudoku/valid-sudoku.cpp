class Solution {
public:
    bool isValid(vector<vector<char>>&board,int r,int c,char &num){
        for(int i=0;i<9;i++){
            if(i==c) continue;
            if(board[r][i]==num) return false;
        }

        for(int i=0;i<9;i++){
            if(i==r) continue;
            if(board[i][c]==num) return false;
        }

        int x=(r/3)*3;
        int y=(c/3)*3;

        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(i==r && j==c) continue;
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(!isValid(board,i,j,board[i][j])){
                    return false;
                }
            }
        }
        return true;
    }
};