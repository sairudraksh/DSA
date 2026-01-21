class Solution {
public:
    int m;
    int n;
    bool isTrue(vector<vector<char>>&boards,int r,int c,int num){
        for(int i=0;i<9;i++){
            if(boards[r][i]-'0'==num) return false;
        }
        for(int i=0;i<9;i++){
            if(boards[i][c]-'0'==num) return false;
        }

        int x=(r/3)*3;
        int y=(c/3)*3;

        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(boards[i][j]-'0'==num) return false;
            }
        }
        return true;
    }
    int f(vector<vector<char>>&board,int r,int c){
        if(r>=n) return true;
        if(c>=m) return f(board,r+1,0);
        if(board[r][c]!='.') return f(board,r,c+1);
        for(int i=1;i<=9;i++){

            if(isTrue(board,r,c,i)){
                board[r][c]=i+'0';

                bool a=f(board,r,c+1);

                if(a==true) return true;

                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        f(board,0,0);
    }
};