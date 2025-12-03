class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid==0 || mid==n-1){
                if(mid==0 && nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(mid==0 && nums[mid]<nums[mid+1]){
                    lo=mid+1;
                }
                if(mid==n-1 && nums[mid]>nums[mid-1]){
                    return mid;
                }
                else if(mid==n-1 && nums[mid]<nums[mid-1]){
                    hi=mid-1;
                }

            }
            else{
                if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
                else if(nums[mid]<nums[mid+1]){
                    lo=mid+1;
                }
                else hi=mid-1;
            }
        }
        return 0;
    }
};