class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums,int i,int j){
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minimum=INT_MAX;
        for(int k=i+1;k<j;k++){
            minimum=min(minimum,nums[i]*nums[j]*nums[k]+find(nums,i,k)+find(nums,k,j));
        }

        return dp[i][j]=minimum;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(values,0,n-1);
    }
};