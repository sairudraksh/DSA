class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=k-1;i<=n-k-1;i++){
            int l=k-1;
            int j=i-1;

            bool flagg=true;

            while(l--){
                if(nums[j]>=nums[j+1]){
                    flagg=false;
                    break;
                }
                j--;
            }

            int p=k-1;
            l=i+1;
            while(p--){
                if(nums[l]>=nums[l+1]){
                    flagg=false;
                    break;
                }
                l++;
            }
            if(flagg==true) return true;
        }
        return false;
    }
};