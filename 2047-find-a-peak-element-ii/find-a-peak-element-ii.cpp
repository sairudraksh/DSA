class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();

        int i=0;
        int j=m-1;

        while(i<=j){
            int mid=i+(j-i)/2;

            int maximum=nums[0][mid];
            int row=0;
            for(int k=0;k<n;k++){
                if(nums[k][mid]>maximum){
                    row=k;
                    maximum=nums[k][mid];
                }
            }
            if((mid==0 || nums[row][mid-1]<nums[row][mid]) &&  (mid==m-1 || nums[row][mid+1]<nums[row][mid])){
                return {row,mid};
            }

            else if(mid!=0 && nums[row][mid-1]>nums[row][mid]){
                j=mid-1;
            }
            else i=mid+1;
        }
        return {};
    }
};