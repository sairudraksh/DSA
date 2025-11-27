class Solution {
public:
    int n;
    int weCanput(vector<int>&nums,int &mid,int &k){
        int count=1;
        int sum=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return false;
            sum+=nums[i];

            if(sum>mid){
                count++;
                sum=nums[i];
            }
        }
        if(count<=k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        n=nums.size();
        int sum=0;
        int minimum=INT_MAX;

        for(int i=0;i<n;i++){
            minimum=min(minimum,nums[i]);
            sum+=nums[i];
        }

        int lo=minimum;
        int hi=sum;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(weCanput(nums,mid,k)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};