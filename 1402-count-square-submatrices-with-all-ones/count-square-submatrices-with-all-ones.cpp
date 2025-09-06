class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(vector<vector<int>>& nums,int i,int j){
        if(i>=n || j>=m || nums[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=1+min({find(nums,i+1,j+1),find(nums,i+1,j),find(nums,i,j+1)});
    }
    int countSquares(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));

        int sum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=find(nums,i,j);
            }
        }

        return sum;
    }
};