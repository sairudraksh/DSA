class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((j==m-1 || nums[i][j+1]<nums[i][j]) && (i==n-1 || nums[i+1][j]<nums[i][j]) && (j==0 || nums[i][j-1]<nums[i][j]) && (i==0 || nums[i-1][j]<nums[i][j])) return {i,j};
            }
        }
        return {};
    }
};