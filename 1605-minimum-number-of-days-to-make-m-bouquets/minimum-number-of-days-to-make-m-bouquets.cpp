class Solution {
public:
    long long find(vector<int>&nums,long long k,long long day){
        long long count=0;
        long long n=nums.size();
        long long bloom=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=day){
                bloom++;
            }
            else{
                bloom=0;
            }
            if(bloom==k){
                count++;
                bloom=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& nums, int m, int together) {
        long long n=nums.size();
        long long maxEle=0;
        long long mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxEle) maxEle=nums[i];
            if(nums[i]<mini) mini=nums[i];
        }

        long long lo=mini;
        long long hi=maxEle;
        long long ans=-1;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            long long x=find(nums,(long long)together,(long long)mid);

            if(x>=m){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};