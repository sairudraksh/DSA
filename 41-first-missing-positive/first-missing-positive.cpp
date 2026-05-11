class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=0 || nums[i]>=n){
                i++;
            }
            else if(nums[i]==i+1){
                i++;
            }
            else if(nums[nums[i]-1]==nums[i]){
                i++;
            }
            else{
                int idx=nums[i]-1;

                swap(nums[i],nums[idx]);
            }
        }
        for(i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1; 
        }
        return nums[nums.size()-1]+1;
    }
};