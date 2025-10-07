class Solution {
public:
    int find(vector<int>&nums,int goal){
        int l=0;
        int r=0;

        int sum=0;
        int count=0;
        if(goal<0) return 0;
        while(r<nums.size()){
            sum+=nums[r];

            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r=r+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=find(nums,goal);
        int b=find(nums,goal-1);
        return a-b;
    }
};