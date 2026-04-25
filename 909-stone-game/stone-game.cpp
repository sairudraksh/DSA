class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&arr,int i,int j){
        if(i>j) return 0;
        else if(i==j) return arr[i];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(arr[i]+find(arr,i+1,j),arr[j]+find(arr,i,j-1));
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int i=0; 
        int j=n-1;
        int a=find(piles,i,j);//alice
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
        }
        int ans=sum-a;
        if(ans>a) return false;
        return true;
    }
};