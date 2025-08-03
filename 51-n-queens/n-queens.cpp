class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<char>>grid;

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
            vector<string>v;
            for(int i=0;i<n;i++){
                string s="";
                for(int j=0;j<n;j++){
                    s+=grid[i][j];
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(wecanput(row,j,n)){
                grid[row][j]='Q';
                find(row+1,n);
                grid[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        ans.clear();
        grid.resize(n,vector<char>(n,'.'));
        find(0,n);
        return ans;
    }
};