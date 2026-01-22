class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int minimum=INT_MAX;
        int maximum=INT_MIN;

        for(int i=0;i<nums.size();i++){
            maximum=max(maximum,nums[i]);
            minimum=min(minimum,nums[i]);
        }
        int lo=1;
        int hi=maximum;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int count=0;
            for(int i=0;i<n;i++){
                int num=nums[i];
                count+=(num/mid);
                if(num%mid>0) count++;
            }
            if(count<=threshold){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};