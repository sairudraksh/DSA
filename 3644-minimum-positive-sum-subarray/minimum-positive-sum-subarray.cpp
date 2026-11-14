class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int minSum=INT_MAX;
        for(int i=0;i<n;i++){
            int currSum=0;
            for(int j=i;j<n;j++){
                currSum+=nums[j];
                if(currSum<minSum && j-i+1>=l && j-i+1<=r && currSum>0){
                    minSum=min(minSum,currSum);
                }
                else if(j-i+1>r){
                    break;
                }
            }
        }
        if(minSum==INT_MAX) return -1;
        return minSum;
    }
};