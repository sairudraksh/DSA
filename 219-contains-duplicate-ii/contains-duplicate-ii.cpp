class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();

        int l=0;
        int j=l+k;

        for(int i=l;i<n;i++){
            for(int m=i+1;m<=i+k && m<n;m++){
                if(nums[m]==nums[i]) return true;
            }

            l++;
            j++;
        }
        return false;
    }
};