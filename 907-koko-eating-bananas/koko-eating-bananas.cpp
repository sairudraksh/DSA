class Solution {
public:
    long long find(vector<int>& nums,long long x){
        long long count=0;

        for(int i=0;i<nums.size();i++){
            if((long long)nums[i]<=x) count++;
            else{
                count+=(long long)nums[i]/x;
                if(nums[i]>x && nums[i]%x!=0) count++;
            }
        }
        return count;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int maxelement=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxelement) maxelement=nums[i];
        }
        long long lo=1;
        long long hi=maxelement;
        long long ans=0;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;

            long long x=find(nums,mid);

            if(x<=h){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};