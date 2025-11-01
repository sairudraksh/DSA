class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;

        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                idx=i;
                break;
            }
        }

        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=-1;
        reverse(nums.begin()+(idx+1),nums.end());

        for(int i=idx+1;i<n;i++){
            if(nums[idx]<nums[i]){
                j=i;
                break;
            }
        }
        int temp=nums[j];
        nums[j]=nums[idx];
        nums[idx]=temp;
    }
};