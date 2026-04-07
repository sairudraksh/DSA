class Solution {
public:
    bool neg;
    int found(int &n,int &m,int &k,vector<vector<int>>&grid){
        int total=grid[n][m];
        int maximum=-10000;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                int num1=0;
                int num2=0;
                int add=0;

                int idx1=m;
                if(i-1>=0){
                    num1=grid[i-1][idx1];
                }
                if(j-1>=0){
                    num2=grid[n][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    add+=grid[i-1][j-1];
                }


                int x=((total-num1)-num2)+add;

                if(x<=k){
                    maximum=max(maximum,x);
                }
            }
        }
        return maximum;
    }
    int isTrue(int &k,vector<vector<int>>&grid){
        int maximum=-10000;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num=grid[i][j];
                if(num==k) return k;
                int a=found(i,j,k,grid);
                if(a<=k){
                    maximum=max(maximum,a);
                }
            }
        }
        return maximum;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        neg=false;
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0) neg=true;
                if(i-1>=0){
                    matrix[i][j]+=matrix[i-1][j];
                }
                if(j-1>=0){
                    matrix[i][j]+=matrix[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    matrix[i][j]-=matrix[i-1][j-1];
                }
            }
       }
       return isTrue(k,matrix);

    }
};