class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();


        int lo=0;
        int hi=m-1;
        while(lo<=hi){
            int mid = lo + (hi - lo) / 2;

            int row = 0;
            int maximum = nums[0][mid];

            for (int i = 1; i < n; i++) {
                if (nums[i][mid] > maximum) {
                    maximum = nums[i][mid];
                    row = i;
                }
            }
            if((mid==m-1 || maximum>nums[row][mid+1]) && (mid==0 || maximum>nums[row][mid-1])){
                    return {row,mid};
                }
            else if(nums[row][mid]<nums[row][mid+1]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return {};
    }
};