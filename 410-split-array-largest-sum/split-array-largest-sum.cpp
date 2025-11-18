class Solution {
public:
    int weCanput(vector<int>&nums,int k,int mid){
        int n=nums.size();
        int count=1;
        int currsum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid) return false;
            currsum+=nums[i];
            if(currsum>mid){
                currsum=nums[i];
                count++;
            }
        }
        if(count>k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k){
        int n=nums.size();
        int l=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            l=min(l,nums[i]);
            sum+=nums[i];
        }
        int r=sum;
        int ans=1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(weCanput(nums,k,mid)){
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        return ans;
    }
};