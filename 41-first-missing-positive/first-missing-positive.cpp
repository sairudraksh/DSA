class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=0 || nums[i]>n){
                i++;
            }
            else if(nums[i]==i+1){
                i++;
            }
            else if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else i++;
        }

        for(int k=0;k<n;k++){
            if(nums[k]!=k+1) return k+1;
        }
        return nums[n-1]+1;
    }
};