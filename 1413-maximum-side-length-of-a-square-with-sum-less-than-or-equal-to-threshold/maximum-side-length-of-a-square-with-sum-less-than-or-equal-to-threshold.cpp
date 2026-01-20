class Solution {
public:
    int find(int &i,int &j,int &r,int &c,vector<vector<int>>&prefix){
        int sum=prefix[r][c];
        if(i>0){
            sum-=prefix[i-1][c];
        }
        if(j>0){
            sum-=prefix[r][j-1];
        }
        if(i>0 && j>0){
            sum+=prefix[i-1][j-1];
        }
        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>prefix;
        prefix.resize(n,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j]=(i>0?prefix[i-1][j]:0)+(j>0?prefix[i][j-1]:0)-((i>0 && j>0)?prefix[i-1][j-1]:0)+mat[i][j];
            }
        }
        int best=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                for(int k=0;k<min(n-i,m-j);k++){
                    int r2=i+k;
                    int c2=j+k;

                    int sum=find(i,j,r2,c2,prefix);

                    if(sum<=threshold){
                        best=max(best,k+1);
                    }
                    else break;
                }
                
            }
        }
        return best;
    }
};