class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n=nums.size();
        int m=nums[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==target) return true;
            }
        }

        return false;
    }
};