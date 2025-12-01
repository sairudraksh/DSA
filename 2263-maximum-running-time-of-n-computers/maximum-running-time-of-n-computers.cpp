class Solution {
public:
    bool weCan(long long mid,int num,vector<int>&nums){
        int n=nums.size();
        long long sum=0;
        long long target=mid*num;
        for(int i=0;i<n;i++){
            sum+=min((long long)nums[i],mid);
        }
        if(sum>=target) return true;
        else return false;
    }
    long long maxRunTime(int n, vector<int>& nums) {
        int p=nums.size();
        long long lo=LLONG_MAX;
        long long hi=0;
        for(int i=0;i<p;i++){
            hi+=nums[i];
            lo=min(lo,(long long)nums[i]);
        }
        hi=hi/n;
        long long ans=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(weCan(mid,n,nums)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};