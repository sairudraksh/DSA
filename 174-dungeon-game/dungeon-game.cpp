class Solution {
public: 
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>&nums,int i,int j){
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1){
            if(nums[i][j]>0)  return 1;
            else return abs(nums[i][j])+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left=find(nums,i+1,j);
        int right=find(nums,i,j+1);

        int need=min(left,right)-nums[i][j];

        return dp[i][j]=max(1,need);
    }
    int calculateMinimumHP(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return find(nums,0,0);
    }
};