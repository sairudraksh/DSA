class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=2;
        int n=nums.size();
        int count=0;
        int maxcount=0;
        while(j<n){
            if(nums[i]+nums[i+1]==nums[j]){
                count++;
                maxcount=max(maxcount,count);
            }
            else count=0;
            i++;
            j++;
        }
        return maxcount+2;
    }
};