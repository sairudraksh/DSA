class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int count=0;
        int ans=nums[0];
        while(i<n){
            if(i!=0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            
            count++;
            ans=nums[0];
            if(count==3) return nums[i];
            i++;
        }
        return nums[0];
    }
};