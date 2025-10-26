class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<char>>grid;
    bool wecanput(int n,int row,int col){
        for(int i=row;i>=0;i--){
            if(grid[i][col]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
    void find(int n,int row){
        if(row>=n){
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
        for(int i=0;i<n;i++){
            if(wecanput(n,row,i)){
                grid[row][i]='Q';
                find(n,row+1);
                grid[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        grid.clear();
        grid.resize(n+1,vector<char>(n+1,'.'));
        find(n,0);
        return ans;
    }
};