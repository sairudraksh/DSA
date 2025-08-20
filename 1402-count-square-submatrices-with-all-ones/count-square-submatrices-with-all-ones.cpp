class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    int find(int i,int j,vector<vector<int>>& nums){
        if(i<0 || j<0 || i>=n || j>=m || nums[i][j]==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=find(i+1,j,nums);
        int left=find(i,j+1,nums);
        int diagonal=find(i+1,j+1,nums);

        return dp[i][j]=1+min({right,left,diagonal});
    }
    int countSquares(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]!=0) count+=find(i,j,nums);
            }
        }
        return count;
    }
};