class Solution {
public:
    double dp[30][30][105];
    double find(int arr[],int arr2[],int i,int j,int n,int k){
        if(i>=n  || j>=n || i<0 || j<0) return 0;
        if(k==0) return dp[i][j][k]=1;
        if(dp[i][j][k]>-0.9) return dp[i][j][k];
        double sum=0;
        for(int l=0;l<8;l++){
            sum+=0.125*find(arr,arr2,i+arr[l],j+arr2[l],n,k-1);
        } 
        return dp[i][j][k]=sum; 
    }
    double knightProbability(int n, int k, int row, int column) {
        int arr[8]={1,2,-1,-2,1,2,-1,-2};
        int arr2[8]={2,1,2,1,-2,-1,-2,-1};
        memset(dp,-1,sizeof dp);
        return find(arr,arr2,row,column,n,k);
    }
};