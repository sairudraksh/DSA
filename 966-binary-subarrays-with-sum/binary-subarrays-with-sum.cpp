class Solution {
public:
    int find(vector<int>&nums,int goal){
        int n=nums.size();
        int count=0;
        int l=0;
        int r=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(l<r && sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal) count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=find(nums,goal);
        int b=find(nums,goal-1);
        return a-b;
    }
};