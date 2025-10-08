class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int lo=1;
        int maximum=-1;
        for(int i=0;i<nums.size();i++){
            maximum=max(nums[i],maximum);
        }
        int hi=maximum;
        int ans=maximum;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            int sum=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    sum++;
                }
                else if(nums[i]%mid==0){
                    sum=sum+(nums[i]/mid);
                }
                else{
                    sum=sum+(nums[i]/mid);
                    sum++;
                }
            }
            if(sum<=threshold){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};