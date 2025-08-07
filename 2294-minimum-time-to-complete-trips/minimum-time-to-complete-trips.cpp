class Solution {
public:
    bool find(vector<int>&nums,long long mid,int totalTrips){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=mid/(long long)nums[i];
        }
        if(count<(long long)totalTrips) return false;
        else return true;
    }
    long long minimumTime(vector<int>& nums, int totalTrips) {
        int n=nums.size();
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
        }

        long long lo=1;
        long long hi=(long long)mx*(long long)totalTrips;
        long long ans=-1;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(find(nums,mid,totalTrips)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }
};