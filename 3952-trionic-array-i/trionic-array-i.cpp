class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();

        int p=-1;
        int q=-1;

        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                p=i+1;
            }
            else break;
        }
        if(p==-1 || p==n-1) return false;

        for(int j=p;j<n-1;j++){
            if(nums[j]>nums[j+1]){
                q=j+1;
            }
            else break;
        }
        if(q==-1 || q==n-1) return false;

        for(int k=q;k<n-1;k++){
            if(nums[k]>=nums[k+1]) return false;
        }
        return true;
    }
};