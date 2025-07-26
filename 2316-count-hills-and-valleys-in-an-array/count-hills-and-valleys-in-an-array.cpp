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
            bool flagg1=false;
            while(nums[l]==nums[i]){
                l--;
                if(l<0){
                    flagg1=true;
                    break;
                }
            }
            if(flagg1==true) continue;

            bool flagg2=false;
            while(nums[r]==nums[i]){
                r++;
                if(r>=n){
                    flagg2=true;
                    break;
                }
            }
            if(flagg2==true) continue;

            if(((nums[l]<nums[i] && nums[i]>nums[r])   ||  (nums[l]>nums[i] && nums[r]>nums[i]))) count++;
        }
        return count;
    }
};