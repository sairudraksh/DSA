class Solution {
public:
    int find(int l,int r,vector<int>&nums,int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;

            if(nums[hi]<nums[mid]){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        } 
        int pivot=lo;
        int idx=find(0,pivot-1,nums,target);
        if(idx!=-1) return true;
        int idx2=find(pivot,n-1,nums,target);
        if(idx2!=-1) return true;
        return false;
    }
};