class Solution {
public:
    bool isTrue(vector<int>&nums,int mid,int k){
        int i=0;
        int count=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                count++;
                i++;
            }
            i++;

            if(count>=k) return true;
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int maximum=INT_MIN;

        int n=nums.size();
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
        }
        int lo=0;
        int hi=maximum;
        int ans=maximum;
        while(lo<=hi){  
            int mid=lo+(hi-lo)/2;

            if(isTrue(nums,mid,k)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }
};