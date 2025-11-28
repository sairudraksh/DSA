class Solution {
public:
    int find(vector<int>&nums,int target,int i){
        if(i>=nums.size()){
            if(target==0) return 1;
            return 0;
        }
        target-=nums[i];
        int a=find(nums,target,i+1);
        target+=nums[i];
        target+=nums[i];
        int b=find(nums,target,i+1);
        target-=nums[i];
        return a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums,target,0);
    }
};