class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int n=nums.size();
        int currsum1=0;
        int currsum2=0; 
        int sum=0;
        for(int i=0;i<n;i++){
            if(i==0) currsum1=nums[0];
            else currsum1=max(nums[i],currsum1+nums[i]);
            maxsum=max(maxsum,currsum1);
            if(i==0) currsum2=nums[0];
            else currsum2=min(nums[i],currsum2+nums[i]);
            minsum=min(minsum,currsum2);

            sum+=nums[i];
        }
        if(maxsum<0) return maxsum;
        return max(maxsum,sum-minsum);
    }
};