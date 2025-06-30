class Solution {
public:
    vector<vector<char>>grid;
    vector<vector<string>>result;
    bool wecanput(int row,int col,int n){
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(grid[i][j]=='Q') return false;
        }
        return true;

    }
    void find(int row,int n){
        if(row==n){
            vector<string>ans;
            for(int i=0;i<n;i++){
                string ans1="";
                for(int j=0;j<n;j++){
                    ans1+=grid[i][j];
                }
                ans.push_back(ans1);
            }
            result.push_back(ans);
            return;
        }
        for(int col=0;col<n;col++){
            if(wecanput(row,col,n)){
                grid[row][col]='Q';
                find(row+1,n);
                grid[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        result.clear();
        grid.resize(n,vector<char>(n,'.'));
        find(0,n);
        return result;
    }
};