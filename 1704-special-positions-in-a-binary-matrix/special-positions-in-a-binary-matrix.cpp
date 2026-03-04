class Solution {
public:
    int n;
    int m;
    bool isTrue(vector<vector<int>>& mat,int &row,int &col){

        for(int i=0;i<m;i++){
            if(i==col) continue;
            if(mat[row][i]==1) return false;
        }

        for(int i=0;i<n;i++){
            if(row==i) continue;
            if(mat[i][col]==1) return false;
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(isTrue(mat,i,j)) count++;
                }
            }
        }
        return count;
    }
};