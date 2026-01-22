class Solution {
public:
    bool isSorted(vector<int>&nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(true){
            int n=nums.size();
            if(isSorted(nums)) return count;
            int minimum=INT_MAX;
            int idx=0;

            for(int i=0;i<n-1;i++){
                if(nums[i]+nums[i+1]<minimum){
                    minimum=nums[i]+nums[i+1];
                    idx=i;
                }
            }
            vector<int>v;
            for(int i=0;i<n;i++){
                if(i==idx){
                    v.push_back(minimum);
                    i++;
                }
                else v.push_back(nums[i]);
            }
            count++;
            nums=v;
        }
        return count;
    }
};