class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 0;
        int count=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]) continue;
            int l=i-1;
            int r=i+1;
            while(nums[l]==nums[i]){
                l--;
                if(l<0){
                    break;
                }
            }
            if(l<0) continue;

            while(nums[r]==nums[i]){
                r++;
                if(r>=n){
                    break;
                }
            }
            if(r>=n) continue;

            if(((nums[l]<nums[i] && nums[i]>nums[r])   ||  (nums[l]>nums[i] && nums[r]>nums[i]))) count++;
        }
        return count;
    }
};