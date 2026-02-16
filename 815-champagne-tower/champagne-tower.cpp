class Solution {
public:
    double dp[101][101];
    double find(int poured,int i,int j){
        if(i<0 || j<0 || i<j) return 0.0;


        if(i==0 && j==0) return poured;
        if(dp[i][j]!=-1) return dp[i][j];
        double left=(find(poured,i-1,j-1)-1)/2.0;
        double right=(find(poured,i-1,j)-1)/2.0;


        if(left<0){
            left=0.0;
        }
        if(right<0){
            right=0.0;
        }

        return dp[i][j]=left+right;

    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        double a=find(poured,query_row,query_glass);
        return min(1.0,a);
    }
};